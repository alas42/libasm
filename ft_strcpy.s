section	.text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx                ; initialize counter
	xor rdx, rdx                ; initialize scratch register 
	cmp rsi, 0
	je ft_strcpy_error
	cmp rdi, 0
	je ft_strcpy_error

ft_strcpy_loop:
	cmp BYTE [rsi + rcx], 0     ; compare the pointed byte with '/0'
	je  ft_strcpy_end           ; jump if equal to bloc ft_srcpy_end
	mov dl, BYTE [rsi + rcx]    ; save the byte in the first byte of rdx
	mov BYTE [rdi + rcx], dl    ; replace the pointed byte from destination string
	inc rcx                     ; increment counter
	jmp ft_strcpy_loop          ; jump to beginning of bloc ft_strcpy_loop

ft_strcpy_end:
	mov dl, 0                   ; put the '\0' in scratch register
	mov BYTE [rdi + rcx], dl    ; terminate the destination string
	mov rax, rdi                ; return value points to destination string
	ret                         ; return rax

ft_strcpy_error:
	xor rax, rax
	ret
