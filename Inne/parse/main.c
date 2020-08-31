#include <stdio.h>
#include <stdlib.h>

struct report {
    unsigned int wordCount;             // Counts all words in input text
    unsigned int longestWord;           // Letters count in longest word
    unsigned int shortestWord;          // Letters count in shortest word
    unsigned int sentenceCount;         // Counts sentences
    unsigned int longestSentence;       // Word count in longest sentence
    unsigned int shortestSentence;      // Word count in shortest sentence
};
int textAnalyze(const char* text, struct report* analyzed);
const char inputData[] = "He shifted on the concrete, feeling it rough and cool through the thin black denim. Nothing here like the\n\
electric dance of Ninsei. This was different commerce, a different rhythm, in the smell of fast food and\n\
perfume and fresh summer sweat. With his deck waiting, back in the loft, an Ono-Sendai Cyberspace 7.\n\
They’d left the place littered with the abstract white forms of the foam packing units, with crumpled\n\
plastic film and hundreds of tiny foam beads. The Ono-Sendai; next year’s most expensive Hosaka\n\
computer; a Sony monitor; a dozen disks of corporate grade ice; a Braun coffee maker. Armitage had\n\
only waited for Case’s approval of each piece. 'Where’d he go?' Case had asked Molly. 'He likes hotels.\n\
Big ones. Near airports, if he can manage it... Let’s go down to the street.' She’d zipped herself into an old\n\
surplus vest with a dozen oddly shaped pockets and put on a huge pair of black plastic sunglasses that\n\
        completely covered her mirrored insets.\n\
Data transfer from Bockris Systems GmbH, Frankfurt, advises, under coded transmission, that content\n\
        of shipment is Kuang Grade Mark Eleven penetration program. Bockris further advises that interface\n\
        with Ono-Sendai Cyberspace 7 is entirely compatible and yields optimal penetration capabilities,\n\
        particularly with regard to existing military systems...\t\t";

int main()
{
    int ret;
    struct report rep;

    ret = textAnalyze(inputData, &rep);


    printf("%d\n", rep.wordCount);
    printf("%d\n", rep.longestWord);
    printf("%d\n", rep.shortestWord);
    printf("%d\n", rep.sentenceCount);

    printf("%d\n", rep.longestSentence);
    printf("%d\n", rep.shortestSentence);

    return 0;
}


int textAnalyze(const char* text, struct report* analyzed)
{
    unsigned int longWord = 0, shortWord = 100,  letter = 0, longSentence = 0, shortSentence = 100, word = 0;
    char lastLetter; //eliminacja podwójnych



    analyzed->sentenceCount = 0;
    (*analyzed).wordCount = 0;

    while (*text != '\0')
    {

        printf("%c", *text);
        //printf("%x\n", *text);

        if (((*text == 0x20) ||  (*text == '\n') || (*text == '\t') || (*text == 0x3b) || (*text == 0x2c) ) && lastLetter != 0) // spacja
        {

            if(lastLetter = 1)
            {
               if (letter < shortWord) shortWord = letter;
               else if (letter > longWord)
               longWord = letter;
               word++;
               printf("%d", word);
            }


            lastLetter = 0;

            letter = 0;
            (*analyzed).wordCount++;




        }
        else if (((*text == 0x21) || (*text == 0x2e) || (*text == 0x3f)) && lastLetter != 0 )
        {
            if(lastLetter == 1)
            {
                word++;
                if (word < shortSentence) shortSentence = word;
                else if (word > longSentence)
                    longSentence = word;

            }



            lastLetter = 0;

            word = 0;   //Zeruj licznik
            letter = 0;
            analyzed->sentenceCount++;  // Counts sentences
            (*analyzed).wordCount++;
        }

        else if(((*text >= 0x41) && (*text <= 0x5a))  || ((*text >= 0x60) && (*text <= 0x7a)))
        {
           letter++;
           lastLetter = 1;
        }
        else if ((*text >= 0x30) && (*text <= 0x39))
        {

            lastLetter = 2;
        }



        text++;

    }

    (*analyzed).longestWord = longWord;           // Letters count in longest word
    (*analyzed).shortestWord = shortWord;          // Letters count in shortest word
    (*analyzed).longestSentence = longSentence;       // Word count in longest sentence
    (*analyzed).shortestSentence = shortSentence;

    return 1;
}
