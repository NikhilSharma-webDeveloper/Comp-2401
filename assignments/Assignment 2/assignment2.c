#include <stdio.h>
#include <string.h>

#define MAX_BUF 256

#define IV  0b10110001
#define KEY 0b11001011
#define CTR 0b00110101

void printBits(unsigned char);
void encode(unsigned char*, unsigned char*, int);
void decode(unsigned char*, unsigned char*, int);

unsigned char processCtr(unsigned char, unsigned char);
unsigned char encryptByte(unsigned char, unsigned char, unsigned char);
unsigned char decryptByte(unsigned char, unsigned char, unsigned char);

int readBytes(unsigned char*, int);

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);


/*
Function:   main
 Purpose:   This is the main function of the program which will first of all
            prompt the user either they want to encode the message or decode
            it.

            If user select to encode it, it will read the input from the user
            and encode the message and print the encrypted text or cypher
            text

            If user select to decode the message, it will read the cypher text
            by the user convert it to the plain text and print it on the screen

  return:   int or the success flag
*/
int main()
{
  char str[8];
  unsigned char input[MAX_BUF];
  unsigned char output[MAX_BUF];
  int choice=0;
  int nOfBytes=0;

  printf("\nYou may:\n");
  printf("  (1) Encrypt a message \n");
  printf("  (2) Decrypt a message \n");
  printf("  (0) Exit\n");
  printf("\n  what is your selection: ");
  fgets(str, sizeof(str), stdin);
  sscanf(str, "%d", &choice);

  if (choice == 0)
    return 0;

  switch (choice) {
    case 1:
      printf("\nEnter Plain Text :\n");
      nOfBytes=readBytes(input, MAX_BUF);
      encode(input,output,nOfBytes);
      printf("\n--------CIPHERTEXT-------\n\n");
      for(int i=0;i<nOfBytes;i++){
        printf("%03d ",*(output+i));
      }
      break;

    case 2:
      printf("\nEnther the CIPHERTEXT <end with -1>\n");
      nOfBytes=readBytes(input, MAX_BUF);
      printf("\n----PLAIN TEXT-----\n");
      decode(input,output,nOfBytes);
      printf("%s\n",output);
      break;
  }
  return(0);
}

/*
Function:  decode
Purpose:   This method does decrypt the whole message input by the user,
           so first of all it as well know we get cyphertext in the combination
           of three character eg 023 so each character in stored in particular
           index in the input array so first of all this method will join the Data
           from the index eg 0 for 0 index, 2 from first index, 3 from third index
           and make 023 then send this particular cyphertext to decodebyte which
           will decode this particular byte return the corresponding character
           and then we store in the index in the plain text array

           Moreover this method will ignore empty spaces and stop converting as
           soon as we get -1 in the input


     in:   ct (cipher text array address)
    out:   pt (plain text array address)
     in:   initialValue (number of byte user entered)
*/
void decode(unsigned char* ct, unsigned char* pt, int nOfBytes){

  unsigned char counter=CTR;
  unsigned char initialValue=IV;
  int j=0;
  for(int i=0;i<nOfBytes;i++){
    counter=processCtr(counter,KEY);

    int targetData=0;

    if(ct[i]!='-' && ct[i+1]!=1){
      for(int k=0;k<=2;k++,i++){
      switch (k) {
        case 0:
        targetData+=(10*10*(ct[i]-'0'));
        break;
        case 1:
        targetData+=(10*(ct[i]-'0'));
        break;
        case 2:
        targetData+=(ct[i]-'0');
      }
    }
  }else{
    break;
  }
  pt[j++]=decryptByte(targetData,counter,initialValue);
  counter++;
  initialValue=targetData;
  }
  pt[j]='\0';
}

/*
Function:  decryptByte
Purpose:   This method does decrypt every bit and return it to the decode function
     in:   ct (cipher text)
     in:   counter
     in:   initialValue
 return:   returns decrypt byte to the decrypt function
*/
unsigned char decryptByte(unsigned char ct, unsigned char counter, unsigned char initialValue){
  unsigned char tempByte=0;

  for(int i=0;i<8;i++){
    int counterCurrentBit=getBit(counter,i);
    int result=0;
    if(counterCurrentBit==1){
      result=(getBit(ct,i)^getBit(initialValue,i));
    }else{
      result=(getBit(ct,i)^getBit(initialValue,7-i));
    }
    if(result==1){
      tempByte=setBit(tempByte,i);
    }
  }

  return tempByte;
}

/*
Function:  encode
Purpose:   This function is used to convert the plain texts to CIPHERTEXT
     in:   pt (Input by the user),size
     in:   size
*/
void encode(unsigned char* pt, unsigned char* ct, int size){
    unsigned char counter=CTR;
    unsigned char initialValue=IV;

    for(int i=0;i<size;i++){
      counter=processCtr(counter,KEY);
      *(ct+i)=encryptByte(*(pt+i),counter,initialValue);
      counter++;
      initialValue=*(ct+i);
    }
}
/*
Function:  processCtr
Purpose:   This function is used to process the counter value which later used
           by the encode function to generate CIPHERTEXT
     in:   counter
     in:   key
 return:   returns the updated counter value
*/
unsigned char processCtr(unsigned char counter, unsigned char key){
  unsigned char tempCounter=counter;
  int start=((counter&1)==1)?1:0;

  for(int i=start;i<8;i=i+2){

    int result=(getBit(counter,i) ^ getBit(key,i));
    int checkBitInkey=getBit(tempCounter,i);

    if((result==0) && (checkBitInkey==1)){
      tempCounter=clearBit(tempCounter,i);
    }else if(result==1 && checkBitInkey==0){
      tempCounter=setBit(tempCounter,i);
    }else{
      continue;
    }
  }
  return tempCounter;
}

/*
Function:  encryptByte
Purpose:   This method does encrypt every bit and return it to the encode function
     in:   inputByte
     in:   counter
     in:   initialValue
 return:   returns encrypted byte to the encode function
*/
unsigned char encryptByte(unsigned char inputByte, unsigned char counter,unsigned char initialValue){
  unsigned char tempByte=0;

  for(int i=0;i<8;i++){
    int counterCurrentBit=getBit(counter,i);
    int result=0;
    if(counterCurrentBit==1){
      result=(getBit(inputByte,i)^getBit(initialValue,i));
    }else{
      result=(getBit(inputByte,i)^getBit(initialValue,7-i));
    }
    if(result==1){
      tempByte=setBit(tempByte,i);
    }
  }

  return tempByte;
}

/*
  Function:  readBytes
  Purpose:   reads characters from the standard output
      out:   the buffer containing the bytes read
       in:   the capacity of the buffer (maximum size)
   return:   the number of bytes actually read from the user
*/
int readBytes(unsigned char* buffer, int max)
{
  int num = 0;

  fgets((char*)buffer, max, stdin);
  num = strlen((char*)buffer) - 1;
  buffer[num] = '\0';

  return num;
}

/*
  Function:  getBit
  Purpose:   retrieve value of bit at specified position
       in:   character from which a bit will be returned
       in:   position of bit to be returned
   return:   value of bit n in character c (0 or 1)
*/
unsigned char getBit(unsigned char c, int n)
{
  return  ((c&(1<<n))>>n);
}

/*
  Function:  setBit
  Purpose:   set specified bit to 1
       in:   character in which a bit will be set to 1
       in:   position of bit to be set to 1
   return:   new value of character c with bit n set to 1
*/
unsigned char setBit(unsigned char c, int n)
{
  return (c | (1 << n));
}

/*
  Function:  clearBit
  Purpose:   set specified bit to 0
       in:   character in which a bit will be set to 0
       in:   position of bit to be set to 0
   return:   new value of character c with bit n set to 0
*/
unsigned char clearBit(unsigned char c, int n)
{
    return (c & (~(1 << n)));
}

/*
Function:  printBits
Purpose:   help only for debugging purposes not any use in the
           whole program just print all the bits of the character and basically
           helps you for debugging
     in:   c
*/
void printBits(unsigned char c){
  printf("Printing Bits\n");
  for(int i=0;i<8;i++){
    printf("%d ",(getBit(c,i)));
  }
}
