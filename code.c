#include <stdio.h>
#include <stdlib.h>


struct Record{
    char name[64];      
    char surname[32];    
    char gender;
    char email[32];
    char phone_number[16];
    char address[32];
    char level_of_education[8];
    unsigned int income_level;
    unsigned int expenditure;  
    char currency_unit[16];
    char currentMood[32];
    float height;
    unsigned int weight;
};

int binaryToXML(char *binFile, char *XMLfile);

int main(){
    binaryToXML("records.dat", "records.xml");

    return 0;
}

int binaryToXML(char *binFile, char *XMLfile){
    struct Record record;
    FILE *dat = fopen(binFile, "rb");
    FILE *xml = fopen(XMLfile, "w");
    fprintf(xml, "<%s>\n",XMLfile);
    if (dat == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    int id = 0;
    while (fread(&record, sizeof(struct Record), 1, dat)) {
        if (id++ != 0 && record.weight != 0) {
            fprintf(xml, "\t<row id=\"%d\">\n", id-1);
            fprintf(xml, "\t\t<name>%s</name>\n", record.name);
            fprintf(xml, "\t\t<surname>%s</surname>\n", record.surname);
            fprintf(xml, "\t\t<gender>%c</gender>\n", record.gender);
            fprintf(xml, "\t\t<email>%s</email>\n", record.email);
            fprintf(xml, "\t\t<phone_number>%s</phone_number>\n", record.phone_number);
            fprintf(xml, "\t\t<address>%s</address>\n", record.address);
            fprintf(xml, "\t\t<level_of_education>%s</level_of_education>\n", record.level_of_education);
            fprintf(xml, "\t\t<income_level>%d</income_level>\n", record.income_level);
            fprintf(xml, "\t\t<expenditure>%d</expenditure>\n", record.expenditure);
            fprintf(xml, "\t\t<currency_unit>%s</currency_unit>\n", record.currency_unit);
            fprintf(xml, "\t\t<currentMood>%s</currentMood>\n", record.currentMood);
            fprintf(xml, "\t\t<height>%.2f</height>\n", record.height);
            fprintf(xml, "\t\t<weight>%d</weight>\n", record.weight);
            fprintf(xml, "\t</row>\n");
        }
    }
    fprintf(xml, "/<%s>\n",XMLfile);
    fclose(dat);
    fclose(xml);
    
    return 0;
}