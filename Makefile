.PHONY: c run_c

c:
	make -C ./p17/c/
	make -C ./p19/c/
	make -C ./p22/c/
	make -C ./p24/c/
	make -C ./p27/c/
	make -C ./p29/c/
	make -C ./p31/c/
	make -C ./p32/c/
	make -C ./p33/c/
	make -C ./p35/c/
	make -C ./p36/c/
	make -C ./p37/c/
	make -C ./p38/c/
	make -C ./p41/c/
	make -C ./p42/c/
	make -C ./p43/c/
	make -C ./p44/c/
	make -C ./p45/c/
	make -C ./p46/c/
	make -C ./p47/c/

run_c:
	@make run -C ./p17/c/
	@make run -C ./p19/c/
	@make run -C ./p22/c/
	@make run -C ./p24/c/
	@make run -C ./p27/c/
	#@make run -C ./p29/c/
	@make run -C ./p31/c/
	@make run -C ./p32/c/
	@make run -C ./p33/c/
	@make run -C ./p35/c/
	@make run -C ./p36/c/
	@make run -C ./p37/c/
	@make run -C ./p38/c/
	@make run -C ./p41/c/
	@make run -C ./p42/c/
	@make run -C ./p43/c/
	@make run -C ./p44/c/
	@make run -C ./p45/c/
	@make run -C ./p46/c/
	@make run -C ./p47/c/
