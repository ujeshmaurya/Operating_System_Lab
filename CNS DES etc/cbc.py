p=input('Enter Plaintext in lowercase alphabetic format: ')
print (p)

b=2 #key for affine

a=19 #key for affine

size=4 #Block size for CBC mode
print ("Block size: ",size)

#now append char to make the length of plaintext even with the block size
app=size-len(p)%size
c=""
tt=""
kind=0
for i in range(0,app):
    c+='a'
for i in range(0,size):
    tt+=chr(97+kind)
    kind+=1
p=c+p
print ("Padded Input: ",p)
print("Initial Vector: ",tt)

#now perform affine cipher
cipher=[]
cipher.append(tt)
fin=""
i=0
ind=0
_ans=[]
while i<len(p):
    temp=""
    ptp=""
    temp2=cipher[ind]
    for j in range(i,i+size):
        ptp+=p[j]
        test=chr(((ord(p[j])-97)^(ord(temp2[j-i])-97))%26+97)
        temp=temp+chr(((ord(test)-97)*a+b)%26+97)
    fin=fin+temp
    _ans.append(ptp)
    cipher.append(temp)
    ind+=1
    i=i+size
print ("Block Cipher : ",cipher[1:])

#now perform decryption
decipher=[]
decipher.append(tt)
flag=0
ainv=0
for i in range(0,26):
    flag=(a*i)%26
    if flag==1:
        ainv=i
        break
i=0
ind=0
_=" "
__ans=[]
while i<len(p):
    temp=""
    temp2=decipher[ind]
    for j in range(i,i+size):
        test=fin[j]
        test1=chr((ainv*(ord(test)-97-b))%26+97)
        temp+=chr(((ord(test1)-97)^(ord(temp2[j-i])-97))%26+97)
    __ans.append(temp)
    decipher.append(fin[i:i+size])
    ind+=1
    i+=size
print("Plaintext Deciphered blocks: ",_,_ans)
#print(__ans)