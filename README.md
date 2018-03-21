# C Exercise
This repository contains a series of exercises done in C.
The details about each program is listed below from easy to advanced:

1. cryptography.c
2.
3.

## cryptography.c

In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet. For example, with a left shift of 3, D would be replaced by A, E would become B, and so on.

Example: The transformation can be represented by aligning two alphabets; the cipher alphabet is the plain alphabet rotated left or right by some number of positions. For instance, here is a Caesar cipher using a left rotation of three places, equivalent to a right shift of 23 (the shift parameter is used as the key):

	Plain: ABCDEFGHIJKLMNOPQRSTUVWXYZ
	Cipher: XYZABCDEFGHIJKLMNOPQRSTUVW

When encrypting, a person looks up each letter of the message in the "plain" line and writes down the corresponding letter in the "cipher" line.

	Plaintext: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
	Ciphertext: QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD

Deciphering is done in reverse, with a right shift of 3.



This program takes two inputs:

1.  A sentence typed in by the user at a prompt.
2.  The key the user plans to use (For the assignment, we will restrict it to a left shift between 1 and 25. Ex, a 3 means shift left by 3 places), typed in at a prompt.

The program displays the original sentence and the encrypted sentence. It then decrypts the encrypted message and displays the decrypted message. The decrypted message and the original message should agree. The input sentence will only be text using alphabets with spaces as in the above example. We will not test it for numbers or special characters.
