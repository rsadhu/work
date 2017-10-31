import smtplib;
from email.mime.text import MIMEText

try:    
    s = smtplib.SMTP('smtp.gmail.com')
    s.starttls()
    
    s.login("rsadhu@infodif.com","webruntime")
    
    s.sendmail("rsadhu@infodif.com","ogonenc@infodif.com","Hello,Testing Python smtp module, Neger:)")        
    s.quit();
except ValueError:
    print("exception"+ValueError)
    