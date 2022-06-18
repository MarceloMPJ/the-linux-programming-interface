include ../Makefile.inc

GEN_EXE = us_xfr_cl us_xfr_sv excercise_1_server excercise_1_client is_seqnum_sv is_seqnum_cl

EXE = ${GEN_EXE}

all : ${EXE}

allgen : ${GEN_EXE}

i6d_ucase_sv.o i6d_ucase_cl.o : i6d_ucase.h

id_echo_cl.o id_echo_sv.o : id_echo.h

read_line.o : read_line.h

is_seqnum_sv.o is_seqnum_cl.o : is_seqnum.h read_line.o

is_seqnum_v2_sv.o is_seqnum_v2_cl.o : is_seqnum_v2.h

scm_cred_recv.o scm_clsred_send.o : scm_cred.h

scm_multi_recv.o scm_multi_send.o : scm_multi.h

scm_rights_recv.o scm_rights_send.o : scm_rights.h

us_xfr_sv.o us_xfr_cl.o : us_xfr.h

us_xfr_v2_sv.o us_xfr_v2_cl.o : us_xfr_v2.h

ud_ucase_sv.o ud_ucase_cl.o : ud_ucase.h

clean :
	${RM} ${EXE} *.o

showall :
	@ echo ${EXE}

${EXE} : ${TLPI_LIB} read_line.o		# True as a rough approximation
