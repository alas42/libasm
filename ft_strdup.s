section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	cmp rdi, 0
	je ft_strdup_error
	call ft_strlen		; param rdi - return rax
	inc rax				; len = ft_strlen + 1, for '/0'
	push rdi			; preserving initial string on stack
	mov rdi, rax		; *rdi = *rax
	call malloc wrt ..plt		; param rdi - return rax
	pop r8				; 'get' the preserved string from the stack
	cmp rax, 0			; compare malloc return with null
	je ft_strdup_error	; jump if equal to ft_strdup_error bloc 
	mov rdi, rax		; destination string
	mov rsi, r8			; source string
	call ft_strcpy		; param 1 : rdi - param 2 : rsi - return rax
	jmp ft_strdup_end	; jump to ft_strdup_end

ft_strdup_error:
	xor rax, rax

ft_strdup_end:
	ret					; return rax
