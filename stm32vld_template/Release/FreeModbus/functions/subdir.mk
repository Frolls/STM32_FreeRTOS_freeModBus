################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeModbus/functions/mbfunccoils.c \
../FreeModbus/functions/mbfuncdiag.c \
../FreeModbus/functions/mbfuncdisc.c \
../FreeModbus/functions/mbfuncholding.c \
../FreeModbus/functions/mbfuncinput.c \
../FreeModbus/functions/mbfuncother.c \
../FreeModbus/functions/mbutils.c 

OBJS += \
./FreeModbus/functions/mbfunccoils.o \
./FreeModbus/functions/mbfuncdiag.o \
./FreeModbus/functions/mbfuncdisc.o \
./FreeModbus/functions/mbfuncholding.o \
./FreeModbus/functions/mbfuncinput.o \
./FreeModbus/functions/mbfuncother.o \
./FreeModbus/functions/mbutils.o 

C_DEPS += \
./FreeModbus/functions/mbfunccoils.d \
./FreeModbus/functions/mbfuncdiag.d \
./FreeModbus/functions/mbfuncdisc.d \
./FreeModbus/functions/mbfuncholding.d \
./FreeModbus/functions/mbfuncinput.d \
./FreeModbus/functions/mbfuncother.d \
./FreeModbus/functions/mbutils.d 


# Each subdirectory must supply rules for building sources it contributes
FreeModbus/functions/%.o: ../FreeModbus/functions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Linux GCC C Compiler'
	arm-elf-gcc -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD_VL -D__ULACCUM_MAX__=0XFFFFFFFFFFFFFFFFP-32ULK -D__SIG_ATOMIC_MAX__=2147483647 -D__INT_FAST32_MAX__=2147483647 -D__THUMB_INTERWORK__=1 -D__SQ_IBIT__=0 -D__USACCUM_MAX__=0XFFFFP-8UHK -D__FLT_EPSILON__=1.1920928955078125e-7F -D__DEC64_MANT_DIG__=16 -D__DBL_MIN__=((double)2.2250738585072014e-308L) -D__LLFRACT_FBIT__=63 -D__SCHAR_MAX__=127 -D"__INT_LEAST64_TYPE__=long long int" -D__LFRACT_IBIT__=0 -D__DEC128_MANT_DIG__=34 -D__GCC_ATOMIC_INT_LOCK_FREE=1 -D"__UINTPTR_TYPE__=unsigned int" -D__HA_IBIT__=8 -D__ACCUM_MAX__=0X7FFFFFFFP-15K -D__LACCUM_IBIT__=32 -D__DBL_MIN_10_EXP__=(-307) -D__FRACT_FBIT__=15 -D__SFRACT_EPSILON__=0x1P-7HR -D__ULFRACT_MIN__=0.0ULR -D__DBL_DENORM_MIN__=((double)4.9406564584124654e-324L) -D__USFRACT_IBIT__=0 -D__LACCUM_MAX__=0X7FFFFFFFFFFFFFFFP-31LK -D__SHRT_MAX__=32767 -D__DBL_HAS_DENORM__=1 -D__UTQ_FBIT__=128 -D__SIZEOF_WCHAR_T__=4 -D__SIZEOF_PTRDIFF_T__=4 -D__SA_IBIT__=16 -D__GXX_TYPEINFO_EQUALITY_INLINE=0 -D__DEC32_MAX__=9.999999E96DF -D__SIZEOF_DOUBLE__=8 -D__SACCUM_IBIT__=8 -D__FLT_MIN_EXP__=(-125) -D__LDBL_MANT_DIG__=53 -D__DEC32_EPSILON__=1E-6DF -D__INTPTR_MAX__=2147483647 -D__LFRACT_MIN__=(-0.5LR-0.5LR) -D__LDBL_DIG__=15 -D__INT_LEAST8_MAX__=127 -D__USQ_IBIT__=0 -D__LDBL_DENORM_MIN__=4.9406564584124654e-324L -D__DEC32_MIN_EXP__=(-94) -D__DEC128_MAX__=9.999999999999999999999999999999999E6144DL -D__LACCUM_FBIT__=31 -D__DA_IBIT__=32 -D__INT_FAST8_MAX__=2147483647 -D__UINT_LEAST8_MAX__=255 -D__ULFRACT_EPSILON__=0x1P-32ULR -D__UACCUM_EPSILON__=0x1P-16UK -D__ULLFRACT_FBIT__=64 -D__FRACT_IBIT__=0 -D__GNUC_PATCHLEVEL__=3 -D__ACCUM_EPSILON__=0x1P-15K -D__DEC32_SUBNORMAL_MIN__=0.000001E-95DF -D__SFRACT_IBIT__=0 -D__SIZEOF_POINTER__=4 -D__WINT_MAX__=4294967295U -D__FLT_MAX_10_EXP__=38 -D__LDBL_HAS_INFINITY__=1 -D__SFRACT_FBIT__=7 -D__DEC64_MIN_EXP__=(-382) -D__ARM_ARCH_4T__=1 -D__ATOMIC_ACQ_REL=4 -D__APCS_32__=1 -D__DEC32_MIN__=1E-95DF -D__ULFRACT_IBIT__=0 -D__ULACCUM_MIN__=0.0ULK -D__USACCUM_EPSILON__=0x1P-8UHK -D__LDBL_MIN_10_EXP__=(-307) -D__UTA_FBIT__=64 -D__SIZEOF_LONG_LONG__=8 -D__UDQ_FBIT__=64 -D__UINT_FAST8_MAX__=4294967295U -D__USFRACT_FBIT__=8 -D__ARM_EABI__=1 -D__DEC64_MAX_EXP__=385 -D__USACCUM_MIN__=0.0UHK -D__LFRACT_FBIT__=31 -D__UACCUM_IBIT__=16 -D__INT16_MAX__=32767 -D__UINT16_C(c)=c -D__LDBL_MAX_EXP__=1024 -D__UINT_LEAST64_MAX__=18446744073709551615ULL -D__FLT_MANT_DIG__=24 -D__FLT_RADIX__=2 -D"__INTMAX_C(c)=c ## LL" -D__ULLFRACT_MAX__=0XFFFFFFFFFFFFFFFFP-64ULLR -D__CHAR_UNSIGNED__=1 -D__UINT8_MAX__=255 -D"__INTMAX_TYPE__=long long int" -D__FLT_DIG__=6 -D__LACCUM_EPSILON__=0x1P-31LK -D"__INT_LEAST32_TYPE__=long int" -D__LDBL_MIN_EXP__=(-1021) -D__LLACCUM_FBIT__=31 -D__UINT32_MAX__=4294967295UL -D__LONG_LONG_MAX__=9223372036854775807LL -D__LLFRACT_IBIT__=0 -D__DBL_HAS_INFINITY__=1 -D"__UINT32_C(c)=c ## UL" -D__FLT_HAS_QUIET_NAN__=1 -D__DBL_MAX_10_EXP__=308 -D__SIG_ATOMIC_TYPE__=int -D__FLT_HAS_DENORM__=1 -D__NO_INLINE__=1 -D__INT_LEAST16_MAX__=32767 -D__DEC128_EPSILON__=1E-33DL -D__FLT_DECIMAL_DIG__=9 -D__GNUC__=4 -D"__INT_LEAST8_TYPE__=signed char" -D__GCC_ATOMIC_WCHAR_T_LOCK_FREE=1 -D__LLFRACT_MAX__=0X7FFFFFFFFFFFFFFFP-63LLR -D__arm__=1 -D__TQ_IBIT__=0 -D__USFRACT_EPSILON__=0x1P-8UHR -D__GCC_ATOMIC_LONG_LOCK_FREE=1 -D__ACCUM_IBIT__=16 -D__TA_IBIT__=64 -D__DEC128_MIN_EXP__=(-6142) -D__UDA_IBIT__=32 -D__SACCUM_FBIT__=7 -D"__UINT_FAST64_TYPE__=long long unsigned int" -D__UTQ_IBIT__=0 -D__INTPTR_TYPE__=int -D__DQ_IBIT__=0 -D"__INT64_TYPE__=long long int" -D__ATOMIC_ACQUIRE=2 -D__DBL_MAX_EXP__=1024 -D"__WINT_TYPE__=unsigned int" -D__FLOAT_WORD_ORDER__=__ORDER_LITTLE_ENDIAN__ -D__ATOMIC_CONSUME=1 -D__DEC64_SUBNORMAL_MIN__=0.000000000000001E-383DD -D__INT_FAST32_TYPE__=int -D"__UINT_FAST8_TYPE__=unsigned int" -D__PTRDIFF_MAX__=2147483647 -D__GCC_ATOMIC_BOOL_LOCK_FREE=1 -D"__INT_LEAST16_TYPE__=short int" -D"__SIZE_TYPE__=unsigned int" -D__UACCUM_FBIT__=16 -D__DEC32_MANT_DIG__=7 -D__LACCUM_MIN__=(-0X1P31LK-0X1P31LK) -D__ATOMIC_RELAXED=0 -D__GCC_ATOMIC_TEST_AND_SET_TRUEVAL=1 -D__DBL_MAX__=((double)1.7976931348623157e+308L) -D__ACCUM_MIN__=(-0X1P15K-0X1P15K) -D__SACCUM_MIN__=(-0X1P7HK-0X1P7HK) -D__INT_FAST16_MAX__=2147483647 -D__SFRACT_MAX__=0X7FP-7HR -D__LLACCUM_EPSILON__=0x1P-31LLK -D__SACCUM_EPSILON__=0x1P-7HK -D__UINT16_MAX__=65535 -D"__UINT_LEAST8_TYPE__=unsigned char" -D__UTA_IBIT__=64 -D__SQ_FBIT__=31 -D"__UINT_FAST32_TYPE__=unsigned int" -D__SFRACT_MIN__=(-0.5HR-0.5HR) -D__LLFRACT_EPSILON__=0x1P-63LLR -D__USA_IBIT__=16 -D__FLT_EVAL_METHOD__=0 -D__UHQ_FBIT__=16 -D__DQ_FBIT__=63 -D"__UINT16_TYPE__=short unsigned int" -D"__UINT32_TYPE__=long unsigned int" -D__PRAGMA_REDEFINE_EXTNAME=1 -D__ARMEL__=1 -D__UFRACT_MIN__=0.0UR -D__UINT_FAST16_MAX__=4294967295U -D__FLT_MAX_EXP__=128 -D__SOFTFP__=1 -D__LDBL_EPSILON__=2.2204460492503131e-16L -D__DEC64_MIN__=1E-383DD -D__VFP_FP__=1 -D__QQ_FBIT__=7 -D"__UINT64_C(c)=c ## ULL" -D__LFRACT_EPSILON__=0x1P-31LR -D__REGISTER_PREFIX__ -D__INT_FAST8_TYPE__=int -D__SA_FBIT__=15 -D__UQQ_IBIT__=0 -D__ULLACCUM_IBIT__=32 -D__ORDER_LITTLE_ENDIAN__=1234 -D__LDBL_HAS_QUIET_NAN__=1 -D__INT8_MAX__=127 -D__FLT_DENORM_MIN__=1.4012984643248171e-45F -D__WCHAR_MIN__=0U -D"__CHAR32_TYPE__=long unsigned int" -D__ELF__=1 -D__ULLFRACT_EPSILON__=0x1P-64ULLR -D__UINTMAX_MAX__=18446744073709551615ULL -D__HQ_FBIT__=15 -D__FLT_MIN_10_EXP__=(-37) -D__UHA_FBIT__=8 -D__UINTPTR_MAX__=4294967295U -D__UINT64_MAX__=18446744073709551615ULL -D__LLFRACT_MIN__=(-0.5LLR-0.5LLR) -D__USACCUM_IBIT__=8 -D__WCHAR_MAX__=4294967295U -D__HA_FBIT__=7 -D__INT_FAST16_TYPE__=int -D__LDBL_HAS_DENORM__=1 -D__GXX_ABI_VERSION=1002 -D__TQ_FBIT__=127 -D__ATOMIC_RELEASE=3 -D__ULLACCUM_MIN__=0.0ULLK -D"__UINTMAX_C(c)=c ## ULL" -D__GCC_ATOMIC_POINTER_LOCK_FREE=1 -D__INT_LEAST64_MAX__=9223372036854775807LL -D__ULLACCUM_EPSILON__=0x1P-32ULLK -D__LLACCUM_IBIT__=32 -D__DBL_MIN_EXP__=(-1021) -D"__UINT_LEAST32_TYPE__=long unsigned int" -D__SIZEOF_LONG_DOUBLE__=8 -D__ACCUM_FBIT__=15 -D__SIZE_MAX__=4294967295U -D__UINT_FAST32_MAX__=4294967295U -D__DA_FBIT__=31 -D__INT_FAST64_MAX__=9223372036854775807LL -D__DBL_DECIMAL_DIG__=17 -D"__SIG_ATOMIC_MIN__=(-__SIG_ATOMIC_MAX__ - 1)" -D__FLT_MIN__=1.1754943508222875e-38F -D__GCC_ATOMIC_CHAR32_T_LOCK_FREE=1 -D__DBL_EPSILON__=((double)2.2204460492503131e-16L) -D__UINT_FAST64_MAX__=18446744073709551615ULL -D__UHA_IBIT__=8 -D__SIZEOF_SIZE_T__=4 -D__DEC128_MAX_EXP__=6145 -D__DBL_DIG__=15 -D__UINT_LEAST16_MAX__=65535 -D__GNUC_MINOR__=7 -D__ORDER_PDP_ENDIAN__=3412 -D__BIGGEST_ALIGNMENT__=8 -D__DEC64_MAX__=9.999999999999999E384DD -D"__UINT_LEAST16_TYPE__=short unsigned int" -D__USACCUM_FBIT__=8 -D__LLACCUM_MAX__=0X7FFFFFFFFFFFFFFFP-31LLK -D__UDA_FBIT__=32 -D__GCC_ATOMIC_SHORT_LOCK_FREE=1 -D__WINT_MIN__=0U -D__INT16_C(c)=c -D__INT64_MAX__=9223372036854775807LL -D__INT_MAX__=2147483647 -D"__INT32_C(c)=c ## L" -D__DEC64_EPSILON__=1E-15DD -D__FRACT_MAX__=0X7FFFP-15R -D__UACCUM_MAX__=0XFFFFFFFFP-16UK -D"__INT32_TYPE__=long int" -D__USES_INITFINI__=1 -D__INT_LEAST32_MAX__=2147483647L -D__STDC__=1 -D__LDBL_MIN__=2.2250738585072014e-308L -D__HQ_IBIT__=0 -D__SACCUM_MAX__=0X7FFFP-7HK -D"__INT8_TYPE__=signed char" -D__BYTE_ORDER__=__ORDER_LITTLE_ENDIAN__ -D__SIZEOF_FLOAT__=4 -D__INTMAX_MAX__=9223372036854775807LL -D__LLACCUM_MIN__=(-0X1P31LLK-0X1P31LLK) -D__USFRACT_MIN__=0.0UHR -D__GCC_ATOMIC_LLONG_LOCK_FREE=1 -D__UFRACT_IBIT__=0 -D"__INT_FAST64_TYPE__=long long int" -D"__UINT64_TYPE__=long long unsigned int" -D__ULLACCUM_FBIT__=32 -D__LFRACT_MAX__=0X7FFFFFFFP-31LR -D__ATOMIC_SEQ_CST=5 -D__DEC32_MAX_EXP__=97 -D__ARM_PCS=1 -D__TA_FBIT__=63 -D__INT32_MAX__=2147483647L -D"__VERSION__="4.7.3 20121207 (release) [ARM/embedded-4_7-branch revision 194305]" -D__UFRACT_EPSILON__=0x1P-16UR -D__UFRACT_FBIT__=16 -D__GCC_ATOMIC_CHAR_LOCK_FREE=1 -D__ULLFRACT_IBIT__=0 -D"__INT64_C(c)=c ## LL" -D__SIZEOF_WINT_T__=4 -D__USER_LABEL_PREFIX__ -D__SIZEOF_INT__=4 -D__LONG_MAX__=2147483647L -D__UHQ_IBIT__=0 -D__INT8_C(c)=c -D__ORDER_BIG_ENDIAN__=4321 -D"__INT16_TYPE__=short int" -D__UINT_LEAST32_MAX__=4294967295UL -D__PTRDIFF_TYPE__=int -D__CHAR_BIT__=8 -D__UINT8_C(c)=c -D__DEC128_SUBNORMAL_MIN__=0.000000000000000000000000000000001E-6143DL -D__DBL_HAS_QUIET_NAN__=1 -D__SIZEOF_SHORT__=2 -D__ULFRACT_MAX__=0XFFFFFFFFP-32ULR -D__FRACT_MIN__=(-0.5R-0.5R) -D__UDQ_IBIT__=0 -D__ULACCUM_FBIT__=32 -D__DEC_EVAL_METHOD__=2 -D__FLT_MAX__=3.4028234663852886e+38F -D__DBL_MANT_DIG__=53 -D"__UINT_FAST16_TYPE__=unsigned int" -D__USA_FBIT__=16 -D"__UINT_LEAST64_TYPE__=long long unsigned int" -D__GNUC_GNU_INLINE__=1 -D__DEC128_MIN__=1E-6143DL -D__ULLACCUM_MAX__=0XFFFFFFFFFFFFFFFFP-32ULLK -D__FLT_HAS_INFINITY__=1 -D"__UINT8_TYPE__=unsigned char" -D__USFRACT_MAX__=0XFFP-8UHR -D__UQQ_FBIT__=8 -D__UFRACT_MAX__=0XFFFFP-16UR -D__STDC_HOSTED__=1 -D__QQ_IBIT__=0 -D__DECIMAL_DIG__=17 -D__LDBL_MAX_10_EXP__=308 -D__UACCUM_MIN__=0.0UK -D__FRACT_EPSILON__=0x1P-15R -D__SIZEOF_LONG__=4 -D__ULACCUM_EPSILON__=0x1P-32ULK -D"__UINTMAX_TYPE__=long long unsigned int" -D__USQ_FBIT__=32 -D__LDBL_MAX__=1.7976931348623157e+308L -D__FINITE_MATH_ONLY__=0 -D__ULFRACT_FBIT__=32 -D"__WCHAR_TYPE__=unsigned int" -D__ULACCUM_IBIT__=32 -D__ULLFRACT_MIN__=0.0ULLR -D__GCC_ATOMIC_CHAR16_T_LOCK_FREE=1 -D"__CHAR16_TYPE__=short unsigned int" -I"/home/frolls/ARM/stm32vld_template/CMSIS" -I"/home/frolls/ARM/stm32vld_template/StdPeripheralDriver/inc" -I/home/frolls/ARM/gcc-arm-none-eabi-4_7-2012q4/lib/gcc/arm-none-eabi/4.7.3/include -I/home/frolls/ARM/gcc-arm-none-eabi-4_7-2012q4/lib/gcc/arm-none-eabi/4.7.3/include-fixed -I/home/frolls/ARM/gcc-arm-none-eabi-4_7-2012q4/arm-none-eabi/include -I/home/frolls/ARM/freemodbus-v1.5.0/modbus -I/home/frolls/ARM/freemodbus-v1.5.0/modbus/functions -I/home/frolls/ARM/freemodbus-v1.5.0/modbus/rtu -I/home/frolls/ARM/freemodbus-v1.5.0/modbus/include -I"/home/frolls/ARM/stm32vld_template/FreeModbus" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/functions" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/include" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/rtu" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32" -I"/home/frolls/ARM/stm32vld_template/FreeModbus/STM32/port" -Os -ffunction-sections -fdata-sections -Wall -std=gnu99 -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


