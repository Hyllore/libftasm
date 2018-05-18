section .text
	global _ft_cat
	extern _write
	extern _read
	extern _malloc

_ft_cat:
	push rbp
	cmp rdi, 0
	jle _end
	mov r12, rdi
	mov rdi, 1024
	call _malloc
	mov rdi, r12
	mov rdx, 1024
	lea rsi, [rel rax]
	call _read
	cmp rax, 0x0
	jl _end
	mov r12, rdi
	mov rdx, rax
	mov rdi, 1
	call _write
	mov rdi, r12
	cmp rax, 0x0
	je _end
;	jmp _ft_cat
	ret

_end:
	pop rbp
	ret
