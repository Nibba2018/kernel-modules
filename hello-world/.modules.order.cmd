cmd_/home/nibba/OSS/kernel-modules/hello-world/modules.order := {   echo /home/nibba/OSS/kernel-modules/hello-world/hello.ko; :; } | awk '!x[$$0]++' - > /home/nibba/OSS/kernel-modules/hello-world/modules.order
