# Makefile forr git push

# TARGETS
.PHONY:	god p

god:
	git status
	git add .
	git status
	git commit -m " -> Makefile Commit <- "
	git status

p:
	git push
