
void testHacker()
{
    char *str = "www.abc.xy";
    int drft = 87;

    //cout<<str<<endl;
    char *tmp=str;

    while(*str!='\0')
    {
        drft =  drft%26;
        char ch =  *str+ drft;


        if(*str>='a' && *str<='z')
        {

            char tmp =  'a'-1;
            *str = ch > 'z' ? tmp + ch-'z': ch;
        }
        else if(*str>='A' && *str<='Z')
        {
            char tmp = 'A'-1;

            *str = ch > 'Z' ? tmp + ch -'Z':ch;
        }
        else
        {
        }

        str++;
    }
    cout<<tmp<<endl;

}
