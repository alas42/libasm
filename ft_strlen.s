section	.text
	global ft_strlen

ft_strlen:
	xor rcx, rcx			; initialize counter
	cmp rdi, 0				; check if pointer is null
	je ft_strlen_end

ft_strlen_loop:
	cmp BYTE [rdi + rcx], 0	; compare the pointed byte with '/0'
	je ft_strlen_end		; jump if equal to ft_strlen_end
	inc rcx					; increment the counter
	jmp ft_strlen_loop		; jump to beginning of bloc ft_strlen_loop

ft_strlen_end:
	mov rax, rcx			; return value equals counter
	ret						; return rax
