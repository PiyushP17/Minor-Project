import traceback
import serial
import matplotlib.pyplot as plt
import csv
import drawnow as dn
import time,datetime

ser_obj = serial.Serial('com3') # Creating Serial object with port com3, port has to be changed according to system.
ser_obj.flushInput()
plt.ion() #plot in interactive mode
i=0 # counter to count no of data points plotted
ys1,ys2,ys3,ys4=[],[],[],[]  # lists for holding sensor data respecitvely from all sensors
header=True  #check to write header in csv. Ensure that the header is written only once in csv file.
def makeFig():
    '''
        makeFig() function draws the real time graph of data points
    '''
    #plt will plot for sensor 1
    plt2,plt3,plt4 = plt,plt,plt # making objects plt2,plt3,plt4 which will plot for sensor 2,3,4 respectively 
    plt.ylim(30,100)  #set limit of y axis ticks values. It has to be changed according to the readings.
    plt.title('Real time Distance using Ultrasonic Sensors')    # Setting title of the plot.
    plt.grid(True)      #Turn the grid mode on.
    plt.ylabel('Distance (cms)') #Set y label
    plt.xlabel('Time')   #Set x label
    plt.plot(ys1, 'ro-', label='Sensor 1')   # Plot sensor 1 data                 
    plt2.plot(ys2,'b^-', label='Sensor 2')   # Plot sensor 2 data
    plt3.plot(ys3,'g*-', label='Sensor 3')   # Plot sensor 3 data
    plt4.plot(ys4,'ks-', label='Sensor 4')   # Plot sensor 4 data
    plt.legend(bbox_to_anchor=(0.99,0.99), loc='best', borderaxespad=0.) #Creating and setting legend for the graph.
    write_csv()  #calling write_csv() to write data in csv.

def write_csv():
    '''
        write_csv() function writes the data into a csv file , which can be analyzed later
    '''
    
    writer = csv.writer(mycsv,delimiter=',',quotechar='|',quoting=csv.QUOTE_MINIMAL, lineterminator='\n')
    if header:   #check to ensure header is only written once in the csv file.  
        writer.writerow(['TimeStamp','Sensor 1','Sensor 2','Sensor 3','Sensor 4','Quadrant'])
    writer.writerow(decoded_data) # Write data in csv file


try: 
    header=True
    with open("data.csv",'w') as mycsv:  # Open csv in write mode
        while True:  # Infinite loop to handle real time data from sensor.
            try:    
                while (ser_obj.inWaiting()==0): #Wait here until there is data from serial port
                    pass
                
                decoded_data=[]  #This list will hold the sensor data combinely.
                ser_data = ser_obj.readline() # ser_data will hold the output line from serial.

                ts = time.time()  #Current System time in ts
                # Formatting 'ts' to bring it in proper csv supportable format.
                timestamp = datetime.datetime.fromtimestamp(ts).strftime('%m-%d-%Y %H:%M:%S') 
                decoded_data.append(timestamp)
                decoded_data += list(map(int,ser_data[0:len(ser_data)-2].decode("utf-8").strip().split()))
                decoded_data.append('1')  # Appending Quadrant no. Has to be changed according to position of object
                print(decoded_data)
                # Store respective sensor data to their respective lists. Used in plotting particular sensor data
                ys1.append(decoded_data[1]) 
                ys2.append(decoded_data[2])
                ys3.append(decoded_data[3])
                ys4.append(decoded_data[4])
                dn.drawnow(makeFig)  # call drawnow function to create Plot.
                header=False
                plt.pause(.05) 
                i+=1

                if(i>30):       #When there are more than 30 data points, pop first element from list
                    ys1.pop(0)  #This allows us to just see the visualization for recent 30 data points
                    ys2.pop(0)
                    ys3.pop(0)
                    ys4.pop(0)
                    #i=0

                ser_data='' #Reset the ser_data object, to hold new line of serial data

            except Exception as e:  # Exception Handling Code
                print(e)
                traceback.print_exc()  
                ser_obj.close()     # If exception occurs, Close serial object, to stop serial communication
                print('Keyboard Interrupt')
                break
finally:
    ser_obj.close()  # Close serial object, to stop serial communication
        
    
