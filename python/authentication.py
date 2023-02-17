#Importing Packages
import smtplib
from email.mime.text import MIMEText
import os
import UTKeyGen

def send_email(to):
  #Sender, Reciever, Body of Email
  key = hex(UTKeyGen.auth_code(to))
  sender = os.getenv('EMAIL')
  receivers = to + '@vols.utk.edu'
  body_of_email = "Here's youre key :D " + key

  #Creating the Message, Subject line, From and To
  msg = MIMEText(body_of_email, 'html')
  msg['Subject'] = 'Subject line goes here'
  msg['From'] = sender
  msg['To'] = receivers

  #Connecting to Gmail SMTP Server
  s = smtplib.SMTP_SSL(host = 'smtp.gmail.com', port = 465)
  s.login( os.getenv('EMAIL'), os.getenv('PASS'))
  s.sendmail(sender, receivers, msg.as_string())
  s.quit()