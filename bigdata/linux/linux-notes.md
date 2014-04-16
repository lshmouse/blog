Linux os Notes

##系统调用的参数传递
系统调用，线程会从用户态陷入到内核态
- 用户态和内核态使用不同的栈空间, (因此不同通过栈来传递参数)
- 系统调用的参数传递是通过寄存器(ebx,ecx,edx,esi和edi)，一般参数不超过6个
- 系统调用的返回值也是通过寄存器
- 用户态和内核态的数据传递是通过copy_to_user和copy_from_user

##函数调用的参数传递




## Block IO

内核IO相关的

http://blog.tao.ma/

