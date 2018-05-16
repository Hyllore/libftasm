section .text
global _ft_strlen

_ft_strlen:
	push rbp
	mov rax, 0
	mov rcx, -1
	cld
	repnz scasb
	not rcx
	mov rax, rcx
	dec rax
	pop rbp
	ret
