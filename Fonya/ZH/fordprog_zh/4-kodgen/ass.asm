global main
extern write_natural
extern read_natural
extern write_boolean
extern read_boolean

section .bss
label3: resd 1
label0: resd 1
label1: resd 1
label2: resb 1

section .text
main:
mov eax,1
mov [label0], eax
mov eax,2
mov [label1], eax
mov al,1
mov [label2], al
mov al,[label2]
cmp al,1
jne near label4
mov eax,[label0]
push eax
mov eax,[label1]
mov ecx,eax
pop eax
add eax,ecx
jmp label5
label4:
mov eax,[label1]
push eax
mov eax,[label0]
mov ecx,eax
pop eax
sub eax,ecx
label5:
mov [label3], eax
mov eax,[label3]
push eax
call write_natural
add esp,4
xor eax,eax
ret
