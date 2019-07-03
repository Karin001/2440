.text
.global _start
_start:
    // 判断nand norflash 并设置 sp指针
    ldr r0, =0
    ldr r1, [r0]
    str r0, [r0]
    ldr r2, [r0]
    cmp r2, r0
    ldr sp, (0x40000000+4096)
    ldreq sp, 4096
    streq r1, [r0]
    b clk_init
clk_init:
    //set lock time max
    ldr r0, =0x4C000000
    ldr r1, =0xffffffff
    str r1, [r0]
    
    // set SDIV=1 PDIV=1 MDIV=92
    /* Mpll = (2 * m * Fin) / (p * 2S)
        m = (MDIV + 8), p = (PDIV + 2), s = SDIV
        Mpll = (2*100*12M)/(3*2) = 400M
    */
    ldr r0, =0x4C000004
    ldr r1, =(92<<12)|(1<<4)|(1<<0)
    str r1,[r0]

    //set HDIVN=2 PDIVN=1 FCLK:HCLK:PCLK = 1:4:8
    ldr r0, =0x4C000014
    ldr r1, =5
    str r1, [r0]
    //
    MMU_SetAsyncBusMode 
    mrc p15,0,r0,c1,c0,0
    orr r0,r0,#0xc0000000 
    mcr p15,0,r0,c1,c0,0

    bl main

