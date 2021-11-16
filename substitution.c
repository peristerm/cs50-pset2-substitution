#include <stdio.h>
#include <string.h>
#include <cs50.h>

//function ekle


int main(int argc, string argv[])
{
    //check if there is a missing command line argument
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    //check if the key doesn't have 26 chars
    string a = argv[1];

    if (strlen(a) != 26)
    {
        return 1;
    }

    int counter = 0;
    //check if the key has alphabetic letters
    for (int f = 0; f < 26; f++)
    {
        if ((a[f] >= 'a' && a[f] <= 'z') || (a[f] >= 'A' && a[f] <= 'Z'))
        {
            continue;
        }

        else
        {
            return 1;
        }
    }
    //check if there are duplicate chars
    for (int l = 0; l < 26; l++)
    {
        for (int h = 0; h < 26; h++)
        {
            if (a[l] == a[h])
            {
                counter++;
            }
        }
    }

    if (counter != 26)
    {
        return 1;
    }
    //get the plaintext
    string b = get_string("plaintext:");

    //change key to uppercase letters
    for (int i = 0; i < 26; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = a[i] - 32;
        }
    }

    int n = strlen(b);

    //turn lowercase chars into ciphertext
    for (int i = 0; i < n; i++)

    {
        if (b[i] == ',' || b[i] == '.' || b[i] == '?' || b[i] == '/' || b[i] == '!' || b[i] == ';' || b[i] == ':')
        {
            continue;
        }
        else if (b[i] >= 'a' && b[i] <= 'z')
        {
            for (int j = 0; j < 26; j++)
            {
                if (a[j] >= 'A' && a[j] <= 'Z')
                {
                    a[j] = a[j] + 32;
                }
            }
            int d;

            d = b[i] - 97;

            b[i] = a[d];

        }
        //turn uppurcase chars into ciphertext
        else if (b[i] >= 'A' && b[i] <= 'Z')
        {
            for (int e = 0; e < 26; e++)
            {
                if (a[e] >= 'a' && a[e] <= 'z')
                {
                    a[e] = a[e] - 32;
                }
            }
            int d;
            d = b[i] - 65;
            b[i] = a[d];


        }



    }






    //print the ciphertext
    printf("ciphertext: %s", b);
    printf("\n");
    //program work well!
    return 0;

}




