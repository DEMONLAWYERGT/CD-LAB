#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#include&lt;ctype.h&gt;
 
char input[10];
int i,error;
void E();
void T();
void Eprime();
void Tprime();
void F(); 
          main()
          {
i=0;
error=0;
                printf(&quot;Enter an arithmetic expression   :  &quot;); // Eg: a+a*a
                gets(input);
                E();
                if(strlen(input)==i&amp;&amp;error==0)
                        printf(&quot;\nAccepted..!!!\n&quot;);
                else printf(&quot;\nRejected..!!!\n&quot;);
                          }
        
          
void E()
{
     T();
     Eprime();
}
void Eprime()
{
     if(input[i]==&#39;+&#39;)
     {
     i++;
     T();
     Eprime();
     }
     }
void T()
{
     F();
     Tprime();
}
void Tprime()
{
     if(input[i]==&#39;*&#39;)
     {
                      i++;
                      F();
                      Tprime();
                      }
                      }
     void F()
     {
          if(isalnum(input[i]))i++;
          else if(input[i]==&#39;(&#39;)
          {
          i++;
          E();
          if(input[i]==&#39;)&#39;)
          i++;
          else error=1;
            }
        
          else error=1;
          }
