String result[5];
  String* a= new String[6];
  String* b= new String[3];
int k = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("hello luban");
  a[0]="001";
  a[1]="002";
  a[2]="004";
  
  b[0]="007";
  b[1]="001";
  b[2] = "099";

  int nOut = 0;
  String* output = new String[12];
  Merge1(a, b, output, 3, 3, nOut);
  Serial.println(nOut);
  Serial.println("result is ");
  for(int i = 0;i<nOut;i++)
  {
    Serial.println(output[i]);
    delay(2);
  }
}
void loop()
{

}
/**
 * @作者：Vijay
 * @邮箱：qioupeng@yeah.net
 * @日期：2018-11-19
 * @功能描述：[合并两个含有nA、nB个元素的有序数组]
 * @param                a     [输入字符串数组a]
 * @param                b     [输入字符串数组b]
 * @param                c     [输出字符串数组c]
 * @param                nA    [输入字符串数组a的元素个数]
 * @param                nB    [输入字符串数组b的元素个数]
 * @param                nCout [输出字符串数组c的元素个数]
 */
void Merge1(String *a, String *b, String *c, int nA, int nB, int& nCout)
{
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;
    for(int j = 0;j<nB;j++){
      Serial.print("开始比较");
      Serial.println(b[j]);
                for (int i = 0;i<nA+1;i++){
                    Serial.print(i);
                  if(i == nA){
                    Serial.println("    最后一个没有加上去");
                    c[k++] = b[j];
                  }else if (strcmp(a[i].c_str(),b[j].c_str())){
                    //不相等，储存b
                    // Serial.print("    不相等i = ");
                    // Serial.println(i);
                    Serial.println("    不相等");
                  }else{
                    Serial.print("    有相等的 ");
                    Serial.print(a[i]);
                    Serial.print(" = ");
                    Serial.println(b[j]);
                    break;
                    //相等，不做操作
                  }
                }
    }
    for(int l = 0;l<nA;l++)
    {
      c[k++] = a[l];
    }
    nCout = k;
}
