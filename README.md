# CS50-Cracker
Cracker for passwords encrypted with classic DES.

The only argument this program takes is a DES-encrypted password.

Passwords up to and including 8 characters have unique encryption. Only the first 8 characters of a password are used in encryption, 
so encrypting Brandons will yield the same password as Brandons2 if the same salt is used.

