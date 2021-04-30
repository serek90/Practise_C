#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

int main()
{
	const char fileName[] = "first_sample.xml";

	/* libxml2 variables */
	xmlDocPtr document;

	/* parse the document */
	document = xmlParseFile(fileName);
	if(document == NULL)
	{
		fprintf(stderr, "Unable to parse xml document %s\n",
							fileName);
		exit(1);
	}

	/* Output the XML version stored in the document */
	if( document->version!=NULL && document->encoding!=NULL)
	{
		printf("%s is XML version %s with %s encoding\n",
			fileName,
			document->version,
			document->encoding
			);
	}
	else
	{
		printf("%s lack either XML version of encoding informtion\n",
			fileName
		      );
	}

	xmlFreeDoc(document);

	return 0;

}
