import serial
import time
import string

import demo_16x16 as display

with serial.Serial('/dev/cu.usbmodem14101', ) as ser :
  while True :
    theTime = time.localtime()
    timerows = display.makepanel(theTime.tm_min, theTime.tm_sec)
    
    data = []
    for row in range(0, len(timerows)) :
      data.append(int(timerows[row]/256))
      data.append(int(timerows[row]%256))

    ser.write(data)
    time.sleep(1/10)
