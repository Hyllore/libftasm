section .bss
	BUF: resb 70000

section .text
	global _ft_cat

_ft_cat:
	push rbp
	cmp rdi, 0x7fffffff
	jg _end
	mov r12, rdi
	lea rsi, [rel BUF]

_main:
	mov rdi, r12
	mov rdx, 70000
	mov rax, 0x2000003
	syscall
	jc _end
;	js _end
;	call _read

	cmp rax, 0
	jle _end
;	mov r12, rdi

	mov rdi, 1
;	lea rsi, [rel BUF]
	mov rdx, rax
	mov rax, 0x2000004
	syscall
;	call _write

;	js _end
	jmp _main


_end:
;	mov rdi, r12
;	mov rax, 0x2000006
;	syscall
;	call _close
	mov rax, 1
	pop rbp
	ret
