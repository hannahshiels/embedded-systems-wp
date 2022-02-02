void binConverter(long input, int arrayLength, char *outPut)
{
    //variable declaration
    int i;   //used in loops to keep the track of indices
    long tempOutput[arrayLength]; //generate an array with the length needed to save the binary values

    //empty the memory allocated to the tempOutput array by iterating over the array replace previous values with 0
    for (i = 0; i < arrayLength; i++)
    {
        //place zero instead of the possible existing values
        tempOutput[i] = 0;
    }

    //get the binary equivalent to the input by saving the remainders of the division of input over 2.
    //The loop continues until the input value is so low that the result of input/2 is less than 1.
    for (i = 0; input > 0; i++)
    {
        //get the remainder value of the number divided by 2 and store it in the tempOutput array
        tempOutput[i] = input % 2;
        //next step
        input = input / 2;
    }
    //print out binary format of the input by starting from the last element in the tempOutput array
    for (i = (arrayLength - 1); i >= 0; i--)
    {
        //prints out the values
        //printf("\n%ld", tempOutput[i]);
        outPut[arrayLength - i - 1] = (char) tempOutput[i];
    }
}