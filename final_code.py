##QWERTY PEN
##Author(s): PRAVEEN GNANASEKARAN, VIJOY SUNIL KUMAR, NESTOR LOBO

import cv2  ##Open CV library used for image inversion to binary 
import numpy as np  ## NUMPY is a support library for cv2 and array manipulation
import serial   ##For serial communication through the terminal
import sys      ##to receive single key press inputs from keyboard

ser=serial.Serial('COM19')  ##Terminal specific to the user's computer
ser.close() ## Terminal closed and reopened as explained in the python website documentation: http://pyserial.readthedocs.io/en/latest/shortintro.html
ser.open()
thresh=130  ## Threshold for image conversion to black and white. Max value is 255 in which case the image is fully black
valid=0  ## check flags used in the program
sze=2   ## size of the (pixel map/100) sent to 8051
while 1:
    y=ser.read() ## wait for ack from 8051
    print "start" 
    sentence_flag=0 ##flags to find sentence length and when to stop
    print_finish=0
    sentence_count=0
    sentence_len=0
    print "ENTER WHAT TO PRINT(a-z)or (A-Z) or (0-9) or * for custom image or ! for a sentence"
    image_name=raw_input() ##uesr input
       
    pixl=20 ##set the square pixel size

    if((image_name>='a' and image_name<='z')  or (image_name>='0' and image_name<='9')): ## conditions for different inputs
        print "SMALL"
        pixx=1 ## to print 20*20 or 200*200
        sentence_len=len(image_name)
        valid=1
    elif(image_name>='A' and image_name<='Z'):
        print "CAPS "
        pixx=1
        sentence_len=len(image_name)
        image_name= "c"+ image_name.lower()
        print image_name
        valid=1
    elif(image_name=='*'): 
        custom_image=raw_input("Enter the name of custom_image: ")
        image_name=custom_image
        pixx=2
        valid=1
    elif(image_name=='!'):
        sentence_array=raw_input("Enter the sentence: ")
        sentence_len= len(sentence_array)
        sentence_flag=1
        pixx=1
        valid=1

    image_extention='.jpg'  ## image extension added for custom inputs

    if valid==1:    ##check for correct user input
        ser.write('%d' %sze)  ## inputs sent to 8051 
        ser.write('%d' %sze)
        ser.write('%d' %pixx)
        ser.write('%d' %sentence_len)
        
        while ((sentence_flag==1) or (pixx!=0)): 
            print "print started"
            if sentence_flag==1:
                if(sentence_array[sentence_count]>='A' and sentence_array[sentence_count]<='Z'):
                    image_name="c"+(sentence_array[sentence_count]).lower() ## file read as ca for the capital alphabet A
                else:
                    image_name=sentence_array[sentence_count]
                
            img= cv2.imread(image_name+image_extention,0) 
            if pixx==1:
                img= cv2.resize(img,(20,20))
            else:
                img= cv2.resize(img,(200,200))
            print "%d %d" %(len(img), len(img[0]))
            
            img = cv2.threshold(img, thresh, 255, cv2.THRESH_BINARY_INV)[1]     ## threshold set for image bitmap conversion
            cv2.imshow(image_name,img)      ##dispaly image on screen to the user
            cv2.waitKey(1000)               ##  wait for a while
            cv2.destroyAllWindows()         ##close the image window

                
            for i,row in enumerate(img):    ##convert the bitmap into a 2D array
                for j,pixel in enumerate(row):
                    if pixel==255:
                        img[i][j]=1
            np.savetxt(image_name+'.txt',img,'%0.0f') ## save the array as a text file locally

            
            glb=1
            if pixx==1:                         ##if the input is a single alphabet or number
                for i in range(0,20):           
                    for j in range(0,20):
                        ser.write('%d' %(img[i][j],))
                        y= ser.read()           ## after every byte of data sent, an ACK is received from the 8051
                        glb=glb+1
                if(sentence_flag==1):
                    y=ser.read()
                    sentence_len=sentence_len-1
                    sentence_count=sentence_count+1
                    print "sent_len %d sent_count %d" %(sentence_len,sentence_count) ##after every 20*20 byte of data sent, the updated values of len and size are sent to 8051
                    ser.write('%d' %sze)
                    ser.write('%d' %sze)
                    ser.write('%d' %pixx)
                    ser.write('%d' %sentence_len)
                    if(sentence_len==0):
                        sentence_flag=0
                        pixx=0
                        print_finish=1
                        print "print finished"
                else:
                    y=ser.read()                ## after every 20*20 chunk, an ACK is received from the 8051
                    pixx=0
                               
            elif pixx==2:                       ## if the input is a custom image, the data is sent in chunks of 20*20 bytes till all the 40000 bytes are transmitted column first
                for k in range(0,pixl/2):
                    for i in range(0,10*pixl):
                        for j in range((k*20),(k*20)+20):
                            ser.write('%d' %(img[i][j],))
                            y=ser.read()
                            print "%d" %glb
                            if((glb)%400==0):
                                y=ser.read()
                            glb=glb+1
                            if glb==40000:
                                pixx=0
                                print_finish=1

                                        
        print ('\n\n\ndone\n')
    else:                                           ##if the user enters an invalid input
        print "INVALID INPUT"
