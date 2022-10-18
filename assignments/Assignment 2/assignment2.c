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
        printf("%03d ",output[i]);
      }
      break;

    case 2:
      printf("Enther the CIPHERTEXT <end with -1>\n");
      nOfBytes=readBytes(input, MAX_BUF);
      decode(input,output,nOfBytes);
      printf("%s\n",output);
      break;
  }

  return(0);
}


void decode(unsigned char* ct, unsigned char* pt, int nOfBytes){

  unsigned char counter=CTR;
  unsigned char initialValue=IV;
  int j=0;
  for(int i=0;i<nOfBytes;i++){
    counter=processCtr(counter,KEY);

    int targetData=0;

    if(ct[i]!='-'){
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
    //  printf("%d %d ",i,targetData);
    }

  }else{
    break;
  }

  printf("  %d \n",targetData);
  pt[j++]=decryptByte(targetData,counter,initialValue);
  counter++;
  initialValue=targetData;
  }
  pt[j]='\0';

}

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

void printBits(unsigned char c){
  printf("Printing Bits\n");
  for(int i=0;i<8;i++){
    printf("%d ",(getBit(c,i)));
  }
}

void encode(unsigned char* pt, unsigned char* ct, int size){
    unsigned char counter=CTR;
    unsigned char initialValue=IV;

    for(int i=0;i<size;i++){
      counter=processCtr(counter,KEY);
      ct[i]=encryptByte(pt[i],counter,initialValue);
      counter++;
      initialValue=ct[i];
    }
}

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
