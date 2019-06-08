def myxor(a,b):
    if a==b:
        return '0'
    else:
        return '1'
#main
p=input('Enter Plaintext in binary format: ')
#key for substitution cipher
key="10"

size=int(input('Enter the block size: ')) #Block size for CBC mode

IV=input('Enter the initial vector of length=size: ') #Initializing vector for CBC

#now append char to make the length of plaintext even with the block size
app=size-len(p)%size
c=""
for i in range(0,app):
    c+='0'
p=c+p
print ("Padded Input: ",p)
print ("Initial Vector: ",IV)

#now perform substitution cipher encryption
cipher=[]
cipher.append(IV)
fin=""
i=0
ind=0
while i<len(p):
    temp=""
    temp2=cipher[ind]
    for j in range(i,i+size):
        test=key[ord(temp2[j-i])-48]
        temp+=myxor(p[j],test)
    fin=fin+temp
    cipher.append(temp)
    ind+=1
    i=i+size
print ("Block Cipher : ",cipher[1:])

#now perform decryption
decipher=[]
decipher.append(IV)
i=0
ind=0
__ans=[]
out=""
while i<len(p):
    temp=""
    temp2=decipher[ind]
    for j in range(i,i+size):
        test=key[ord(temp2[j-i])-48]
        temp+=myxor(test,fin[j])
    __ans.append(temp)
    decipher.append(fin[i:i+size])
    out+=temp
    ind+=1
    i+=size
print("Plaintext Deciphered blocks: ",__ans)
print("Deciphered Output: ",out)
if(p==out):
    print("RESULT: Input(Padded) and Output binary strings are matching.")