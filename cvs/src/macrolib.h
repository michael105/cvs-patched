
#define  __FOREACH0(F,sep,a,...) sep F(a) __VA_OPT__( ERROR: too many agruments at __LINE__ )
#define  __FOREACH1(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH0(  F,sep, __VA_ARGS__) )
#define  __FOREACH2(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH1(  F,sep, __VA_ARGS__) )
#define  __FOREACH3(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH2(  F,sep, __VA_ARGS__) )
#define  __FOREACH4(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH3(  F,sep, __VA_ARGS__) )
#define  __FOREACH5(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH4(  F,sep, __VA_ARGS__) )
#define  __FOREACH6(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH5(  F,sep, __VA_ARGS__) )
#define  __FOREACH7(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH6(  F,sep, __VA_ARGS__) )
#define  __FOREACH8(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH7(  F,sep, __VA_ARGS__) )
#define  __FOREACH9(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH8(  F,sep, __VA_ARGS__) )
#define __FOREACH10(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH9(  F,sep, __VA_ARGS__) )
#define __FOREACH11(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH10( F,sep, __VA_ARGS__) )
#define __FOREACH12(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH11( F,sep, __VA_ARGS__) )
#define __FOREACH13(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH12( F,sep, __VA_ARGS__) )
#define __FOREACH14(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH13( F,sep, __VA_ARGS__) )
#define __FOREACH15(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH14( F,sep, __VA_ARGS__) )
#define __FOREACH16(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH15( F,sep, __VA_ARGS__) )
#define __FOREACH17(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH16( F,sep, __VA_ARGS__) )
#define __FOREACH18(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH17( F,sep, __VA_ARGS__) )
#define __FOREACH19(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH18( F,sep, __VA_ARGS__) )
#define __FOREACH20(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH19( F,sep, __VA_ARGS__) )
#define __FOREACH21(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH20( F,sep, __VA_ARGS__) )
#define __FOREACH22(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH21( F,sep, __VA_ARGS__) )
#define __FOREACH23(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH22( F,sep, __VA_ARGS__) )
#define __FOREACH24(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH23( F,sep, __VA_ARGS__) )
#define __FOREACH25(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH24( F,sep, __VA_ARGS__) )
#define __FOREACH26(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH25( F,sep, __VA_ARGS__) )
#define __FOREACH27(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH26( F,sep, __VA_ARGS__) )
#define __FOREACH28(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH27( F,sep, __VA_ARGS__) )
#define __FOREACH29(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH28( F,sep, __VA_ARGS__) )
#define __FOREACH30(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH29( F,sep, __VA_ARGS__) )
#define __FOREACH31(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH30( F,sep, __VA_ARGS__) )
#define __FOREACH32(F,sep,a,...) sep F(a) __VA_OPT__( __FOREACH31( F,sep, __VA_ARGS__) )


//+doc call each macro F for each argument a,...
// separate them with sep
//+def FOREACH
#define FOREACH( F,sep, a, ... ) F(a) __VA_OPT__( __FOREACH32( F,sep, __VA_ARGS__) )

