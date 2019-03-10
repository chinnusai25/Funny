//calculating the 10th fibonnaci number using recursion.
.text

#.data
.globl main
.type main,@function

main:
movq $0xa,%rdi
movq $0x0,%rdx
movq $0x0,%rax
callq fib
retq 

fib:
	subq $24,%rsp			#function prologue
	movq %rdi,16(%rsp)		#16(%rsp)=n
	cmpq $0x0,%rdi			
	je .Lzero
	cmpq $0x1,%rdi
	je .Lone
	cmpq $0x0,%rdi
	jl .Lexit  
					
	subq $0x1,16(%rsp)		
	movq 16(%rsp),%rdi		# %rdi=n-1

	callq fib				
	movq %rax,(%rsp)			# (%rsp)=%rax	i.e n1
		
	subq $0x1,16(%rsp)		
	movq 16(%rsp),%rdi		# %rdi=(n-1)-1

	callq fib
	movq %rax,8(%rsp)			# 8(%rsp)=%rax  i.e n2

	movq (%rsp),%rax		# %rax+=(%rsp)  rax+=n1
	addq 8(%rsp),%rax		# %rax+=8(%rsp) rax+=n2
	addq $24,%rsp			#function epilogue	
	retq

.Lzero:
#movq %rdi,%rax
	movq $0x0,%rax
	addq $24,%rsp
	retq

.Lone:
	movq $0x1,%rax
	addq $24,%rsp		
	retq

.Lexit:
	ret	
