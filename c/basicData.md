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



|      |      |
| ---- | ---- |
|      |      |

|