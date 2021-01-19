# The Record as to C Language

> Keyword

  assert(condition_clause): 宏
  ```c
 	int void main(){
	  //the front clause

	  assert(1 == 2); //当（1 == 2)成立时，程序继续向下执行，否则程序终止执行，在console中打印相关信息(哪一行、那个文件等)

	  //the front clause
	}
  ```
> 数组

  ```c

  	// 1.在函数中传递参数为数组：
		oneArr(int arr[])	{
			
		}
  	int main(void){
		int arr[10];	

		// 1. 在oneArr中sizeof(arr)等于4，在oneArr中接受的只是原来数组的第一个元素，可以通过指针去遍历原数组中所有的元素，但无法判断原数组的结束位置。
		oneArr(arr);
	}
  ```

> C语言数据类型

* 基本类型
  * 数值类型
    * 短整型 
      * short
    * 整型
      * int
    * 长整型
      * long
    * 单精度型
      * float
    * 双精度型
      * double
  * 字符类型
    * char
* 构造类型
  * 数组
  * 结构体 
    * struct
  * 共用体
    * union
  * 枚举类型
    * enum
* 指针类型
* 空类型
  * void


* common function

  | Header File | Function         |
  | ----------- | ---------------- |
  | float.h     | FLT_MIN, FLT_MAX |

  | 类型        | 比特数 | 有效数字 | 数值范围         |
  | ----------- | ------ | -------- | ---------------- |
  | float       | 32     | 6~7      | 10^-37~10^38     |
  | double      | 64     | 15~16    | 10^-307~10^308   |
  | long double | 128    | 18~19    | 10^-4931~10^4932 |

* 字符串

  ```
  char name[];
  char *name;
  ```

* math

  ```
  sqrt()
  pow()
  ```

* 字符输入输出

  ```
  scanf()
  printf()
  
  getchar()
  putchar()
  ```

* main(int args, char *argv[])

  ```
  args : the number of parameter 程序自动检测 *rgv数组长度
  argv : 
  	the array of parameter 
  	argv[0] : the first parameter
  	...
  ```

* 字符数组

  ```
  char c[] = "Nori";
  ```

  | Header             | Function          |
  | ------------------ | ----------------- |
  | #include<string.h> | puts()<br/>gets() |


* 在32位的系统中

  ```c
  short 2 byte
  int, float, long 4 byte
  double8 byte
  
  指针长度 4byte	(在64位中为 8 byte)
  
  ```

* union & struct

  ```c
  union Un{
      int i;
      double d;
      char c;
  };
  
  typedef struct{
      int i;
      double d;
      char c;
  }Node;
  typedef struct{
      int i;
      char c;
      double d;
  }Node1;
  
  ...main(){
      Node n;
      Node n1;
      Un u;
      
      // Output 24
      sprintf("%d", sizeof(n)); 
     
      // Output 16
      sprintf("%d", sizeof(n1));
      
      // Output 8
      sprintf("%d", sizeof(u));
  }
  ```

  