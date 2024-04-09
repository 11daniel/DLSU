#include "LASTNAME-secret.c"

int
main()
{
   string   word, 
            encrypted,
            decrypted, 
			secretKey;
   sentence input,
            output;
   arrWords aWords1,
            aWords2 = {"how", "are", "you", "doing"},
			aRes1,
			aRes2;
   int      nElem, i, nElem2;

   printf("Key: ");
   scanf("%s ", secretKey);
   printf("Word: ");
   scanf("%s ", word);
  
   //Testing Encrypt()
   Encrypt(encrypted, word, secretKey);
   printf("Encrypted %s into %s\n\n", word, encrypted);
   
   //Testing Decrypt()
   Decrypt(decrypted, encrypted, secretKey);
   printf("Decrypted %s into %s\n", encrypted, decrypted);   
   Decrypt(decrypted, word, secretKey);
   printf("Decrypted %s into %s\n\n", word, decrypted);   

   //Testing Tokenize()
   printf("Sentence: ");
   getInput(input);
   nElem = Tokenize(aWords1, input);
   display(aWords1, nElem);

   //Testing Merge()
   Merge(output, aWords2, 4);
   printf("Merged message = \"%s\"\n\n", output);
   
   //Combined Testing 
   nElem2 = Tokenize(aWords2, output);
   for (i = 0; i < nElem2; i++)
      Encrypt(aRes1[i], aWords2[i], secretKey);
   
   for (i = 0; i < nElem; i++)
      Decrypt(aRes2[i], aWords1[i], secretKey);

   Merge(output, aRes1, nElem2);
   printf("Merged Encrypted = \"%s\"\n", output);
   Merge(output, aRes2, nElem);
   printf("Merged Decrypted = \"%s\"\n", output);
   
   return 0;
}
