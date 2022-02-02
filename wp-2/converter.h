char* hexToBin(char element)
{
    if (element == '0')
    {
        return "0000";
    } else if (element == '1')
    {
        return "0001";
    }else if (element == '2')
    {
        return "0010";
    }else if (element == '3')
    {
        return "0011";
    }else if (element == '4')
    {
        return "0100";
    }else if (element == '5')
    {
        return "0101";
    }else if (element == '6')
    {
        return "0110";
    }else if (element == '7')
    {
        return "0111";
    }else if (element == '8')
    {
        return "1000";
    }else if (element == '9')
    {
        return "1001";
    }else if (element == 'A' || element == 'a')
    {
        return "1010";
    }else if (element == 'B' || element == 'b')
    {
        return "1011";
    }else if (element == 'C' || element == 'c')
    {
        return "1100";
    }else if (element == 'D' || element == 'd')
    {
        return "1101";
    }else if (element == 'E' || element == 'e')
    {
        return "1110";
    }else if (element == 'F' || element == 'f')
    {
        return "1111";
    }

return "false";
}


int binToDec(int bin)
{
    int i = 1;
    int remainder;
    int result = 0;

    while (bin != 0) //teh loop continues until the binary format divided by 10 has a value less than 1
    {
        remainder = bin % 10;          //get the last digit of the binary format
        result = result + remainder * i; // multiply the remainder by its corresponding power of two and add it to
        // result
        i = i * 2;                       //go to the next power of two
        bin = bin / 10;              //remove the last digit of the input
    }

    return result;

}
