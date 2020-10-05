import smtplib
sender='thesender@gmail.com'
receiver='whicheverreceiver@gmail.com'
password=’<put your password here>'
smtpserver=smtplib.SMTP("smtp.gmail.com",587)
smtpserver.ehlo()
smtpserver.starttls()
smtpserver.ehlo
smtpserver.login(sender,password)
msg='Subject:Demo\nThis is a dem
smtpserver.sendmail(sender,receiver,msg)
print('Sent')
smtpserver.close()