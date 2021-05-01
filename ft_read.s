section	.text
	global ft_read
    extern __errno_location

ft_read:
    mov rax, 0				; rax register equals 0
	syscall					; param : rax = read | rdi = fd | rsi = *buf| rdx = *count
    cmp rax, 0				; compare return value of syscall with 0
    jl ft_read_error		; jump if inferior to ft_read_error
    jmp ft_read_end			; jump to bloc ft_read_end

ft_read_error:
    neg rax					; negate rax - transform it into a positiv value
    push rax				; push/(save) the value of rax in the stack
    call __errno_location wrt ..plt	; return in rax register the pointed memory of errno
    pop rdi					; pull the former value of rax in rdi
    mov [rax], rdi			; put the former value of rax in the location of errno
    mov rax, -1				; value of rax equals to -1

ft_read_end:
    ret						; return rax
