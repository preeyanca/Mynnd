
 

#define SIZE_ARRAY 300

int calculator(int arg1,int arg2,int operand){
  //To perform basic calculation
    if(operand==0)return arg1+arg2;
    else if(operand==1)return arg1-arg2;
    if(operand==2)return arg1*arg2;
    return arg1/arg2;
}


void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;
    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}
 

void setup()
{
  
  Serial.begin(9600);
  Serial.println("Initializing Calculator...\nEnter the calculation to be performed:");
}
 
void loop()
{
  static char incomingData[SIZE_ARRAY];
  
  if(Serial.available())
  {
    
    String incomingString = Serial.readString();
    Serial.print("Calculation to be performed: ");
    Serial.println(incomingString);
    const char* str = incomingString.c_str();
    removeSpaces(str);
    Serial.println(incomingString);

    int i=0,j=0,k=0;
    bool flag_arg2=0,flag_err=0;
    int operand=5;
    char arg1[100]={0},arg2[100]={0};

    while(incomingString[i]!='\0')
    {
            
            if(incomingString[i]!='\n'&&incomingString[i]!='\r'&&incomingString[i]!='+'&&incomingString[i]!='-'&&incomingString[i]!='*'&&incomingString[i]!='/')
            {
              if(incomingString[i] < '0' || incomingString[i] > '9')
              {
                  flag_err=1;
                  break;
              }
            }
            
            if(incomingString[i]=='+'||incomingString[i]=='-'||incomingString[i]=='*'||incomingString[i]=='/')
            {
              flag_arg2=1;
              if(incomingString[i]=='+')operand=0;
              else if(incomingString[i]=='-')operand=1;
              else if(incomingString[i]=='*')operand=2;
              else operand=3;
              i++;
              
            }

            if(flag_arg2==0)
            {
              arg1[j++]=incomingString[i++];
            }
            else if(flag_arg2==1)
            {
              arg2[k++]=incomingString[i++];
            }

    }
// Serial.println("Argument 1=");
// Serial.println(arg1);
// Serial.println("Argument 2=");
// Serial.println(arg2);
if(flag_err==0){
    Serial.println("Answer");
    Serial.println(calculator(atoi(arg1),atoi(arg2),operand));
}
else Serial.println("Invalid Data");
}
   
  delay(100);
}