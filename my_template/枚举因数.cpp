int a;      //分解a的因子数
  int b[100005];  // 将a的所有因子数保存在b数组 
  scanf("%d",&a);
  int z=0;
  for(int i=1;i*i<=a;i++) {
   if(a%i==0) {
    b[z++]=i;    
    if(i!=a/i)      //两个因子数不相等则保存下来
    b[z++]=a/i;   
   }
 }
 sort(b, b+z);  //将因子数从小到大排序然后输出
