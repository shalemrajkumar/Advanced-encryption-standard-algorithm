from Crypto.Cipher import AES                            # AES 256 Bit Encryption
import hashlib
Password =raw_input("Please Enter your Key").encode()      # encode converts password to bytes 
key = hashlib.sha256(Password).digest()                  # we need to key in 128,192,256 bit  so with hash function using SHA256 Algorithm we are making a 256bit hash for our password
Mode=AES.MODE_CBC
initial-vector='Hi this is AES123'



ciphertext=AES.new(key,mode,initial-vector)



with open('file.extension','rb') as f:
    file=f.read()

encrypted_message=cipher.encrypt(message)

with open('encrypred,wb') as e:
    e.write(encrypted_message)