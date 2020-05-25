   .model      small
    .8086


    .data

lower   db      'a'


    .code

start:
        mov     ax,@data
        mov     ds,ax

        mov     ah,8
        int     21h
        mov     dl,al
        mov     ah,2
        int     21h

exit:
        mov     ax,4c00h
        int     21h
        end     start
