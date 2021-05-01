section	.text
	global ft_strcmp

ft_strcmp:
    xor rcx, rcx                ; initialize counter
    xor rdx, rdx                ; initialize scratch regsiter
	xor rax, rax				; only thing added

ft_strcmp_loop:
    mov al, BYTE [rsi + rcx]    ; save the byte in the first byte of rax register
    mov dl, BYTE [rdi + rcx]    ; save the byte in the first byte of rdx register
    cmp al, 0                   ; compare the pointed byte (src) with '/0'
    je  ft_strcmp_end           ; jump if equal to bloc ft_strcmp_end
    cmp dl, 0                   ; compare the pointed byte (dest) with '/0'
    je  ft_strcmp_end           ; jump if equal to bloc ft_strcmp_end
    cmp al, dl                  ; compare both bytes values
    jne ft_strcmp_end           ; jump if not equal to ft_strcmp_end
    inc rcx                     ; increment counter
	jmp ft_strcmp_loop          ; jump to beginning of bloc ft_strcmp_loop

ft_strcmp_end:
    sub rdx, rax                ; rdx = rdx - rax 
    mov rax, rdx                ; return value equals difference
    ret                         ; return rax
