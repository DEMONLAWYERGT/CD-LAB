#include&lt;stdio.h&gt;
#include&lt;ctype.h&gt;
#include&lt;string.h&gt;
void followfirst(char, int, int);
void follow(char c);
void findfirst(char, int, int);
int count, n = 0;
char calc_first[10][100];
char calc_follow[10][100];
int m = 0;
char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;
int main(int argc, char **argv)
{
  int jm = 0;
int km = 0;
int i, choice;
char c, ch;
count = 8;
strcpy(production[0], &quot;E=TR&quot;);
strcpy(production[1], &quot;R=+TR&quot;);
strcpy(production[2], &quot;R=#&quot;);
strcpy(production[3], &quot;T=FY&quot;);
strcpy(production[4], &quot;Y=*FY&quot;);
strcpy(production[5], &quot;Y=#&quot;);
strcpy(production[6], &quot;F=(E)&quot;);
strcpy(production[7], &quot;F=i&quot;);
int kay;
char done[count];
int ptr = -1;
for(k = 0; k &lt; count; k++) {
for(kay = 0; kay &lt; 100; kay++) {
calc_first[k][kay] = &#39;!&#39;;
}
}
int point1 = 0, point2, xxx;
for(k = 0; k &lt; count; k++)
{
c = production[k][0];
point2 = 0;
xxx = 0;
for(kay = 0; kay &lt;= ptr; kay++)
if(c == done[kay])
xxx = 1;
if (xxx == 1)
continue;
findfirst(c, 0, 0);
ptr += 1;
done[ptr] = c;
printf(&quot;\n First(%c) = { &quot;, c);
calc_first[point1][point2++] = c;
for(i = 0 + jm; i &lt; n; i++) {
int lark = 0, chk = 0;
for(lark = 0; lark &lt; point2; lark++) {
if (first[i] == calc_first[point1][lark])
{
chk = 1;
break;
}
}
if(chk == 0)
{
printf(&quot;%c, &quot;, first[i]);
calc_first[point1][point2++] = first[i];
}
}
printf(&quot;}\n&quot;);
jm = n;
point1++;
}
printf(&quot;\n&quot;);
printf(&quot;-----------------------------------------------\n\n&quot;);
char donee[count];
ptr = -1;
for(k = 0; k &lt; count; k++) {
for(kay = 0; kay &lt; 100; kay++) {
calc_follow[k][kay] = &#39;!&#39;;
}
}
point1 = 0;
int land = 0;
for(e = 0; e &lt; count; e++)
{
ck = production[e][0];
point2 = 0;
xxx = 0;
for(kay = 0; kay &lt;= ptr; kay++)
if(ck == donee[kay])
xxx = 1;
if (xxx == 1)
continue;
land += 1;
follow(ck);
ptr += 1;
donee[ptr] = ck;
printf(&quot; Follow(%c) = { &quot;, ck);
calc_follow[point1][point2++] = ck;
for(i = 0 + km; i &lt; m; i++) {
int lark = 0, chk = 0;
for(lark = 0; lark &lt; point2; lark++)
{
if (f[i] == calc_follow[point1][lark])
{
chk = 1;
break;
}
}
if(chk == 0)
{
printf(&quot;%c, &quot;, f[i]);
calc_follow[point1][point2++] = f[i];
}
}
printf(&quot; }\n\n&quot;);
km = m;
point1++;
}
}
void follow(char c)
{
int i, j;
if(production[0][0] == c) {
f[m++] = &#39;$&#39;;
}
for(i = 0; i &lt; 10; i++)
{
for(j = 2;j &lt; 10; j++)
{
if(production[i][j] == c)
{
if(production[i][j+1] != &#39;\0&#39;)
{
followfirst(production[i][j+1], i, (j+2));
}
if(production[i][j+1]==&#39;\0&#39; &amp;&amp; c!=production[i][0])
{
follow(production[i][0]);
}
}
}
}
}
void findfirst(char c, int q1, int q2)
{
int j;
if(!(isupper(c))) {
first[n++] = c;
}
for(j = 0; j &lt; count; j++)
{
if(production[j][0] == c)
{
if(production[j][2] == &#39;#&#39;)
{
if(production[q1][q2] == &#39;\0&#39;)
first[n++] = &#39;#&#39;;
else if(production[q1][q2] != &#39;\0&#39;
&amp;&amp; (q1 != 0 || q2 != 0))
{
findfirst(production[q1][q2], q1, (q2+1));
}
else
first[n++] = &#39;#&#39;;
}
else if(!isupper(production[j][2]))
{
first[n++] = production[j][2];
}
else
{
findfirst(production[j][2], j, 3);
}
}
}
}
void followfirst(char c, int c1, int c2)
{
int k;
if(!(isupper(c)))
f[m++] = c;
else
{
int i = 0, j = 1;
for(i = 0; i &lt; count; i++)
{
if(calc_first[i][0] == c)
break;
}
while(calc_first[i][j] != &#39;!&#39;)
{
if(calc_first[i][j] != &#39;#&#39;)
{
f[m++] = calc_first[i][j];
}
else
{
if(production[c1][c2] == &#39;\0&#39;)
{
follow(production[c1][0]);
}
else
{
followfirst(production[c1][c2], c1, c2+1);
}
}
j++;
}
}
}
