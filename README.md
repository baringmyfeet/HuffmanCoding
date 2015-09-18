# HuffmanCoding (C++)

Huffman Coding Project Statement

(a) Given a text file, text_1, the program is to compute the histogram of the characters in the text, and output a list of pairs <character prob> to an output file, out1. Out1 will be the input for the construction of sorted 
linked list. 

(b) After the construction of sorted linked list, the construction of binary tree, and the construction of entropy table, a second text file, text_2 is opened and encoded, based on the coding scheme in the entropy table; then, the encoded text is written to an output file, called code_2.

(c) Then, the program will re-open the file code_2, and decode code_2  and output to an output file, called decode_2.


Argument documentation
/* argv[1] = input file for making the histogram
 * argv[2] = histogram output, and input file for making the linked list
 * argv[3] = iteration record output, for linked list
 * argv[4] = output for sorted character and probability pairs
 * argv[5] = iteration record output, for binary tree
 * argv[6] = output for entire linked list
 * argv[7] = entropy table output
 * argv[8] = input file for encoding
 * argv[9] = encoded output, and input file to be decoded
 * argv[10] = decoded output
 */
