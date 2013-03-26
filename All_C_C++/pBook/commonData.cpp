#include"commonData.h"

Contact::Contact(char *f, char *l, char *m, char *ll)
{
    qDebug()<<"Contact::Contact::paras\n";
    fname= strdup(f);
    lname = strdup(l);
    mob = strdup(m);
    landline = strdup(ll);
}

Contact::Contact(Contact *tmp)
{
    qDebug()<<"Contact::Contact::para::contact\n";
    fname= strdup(tmp->fname);
    lname = strdup(tmp->lname);
    mob = strdup(tmp->mob);
    landline = strdup(tmp->landline);
}

Contact::~Contact()
{
    qDebug()<<"Contact::~Contact\n";
    free(fname);
    free(lname);
    free(mob);
    free(landline);
}
