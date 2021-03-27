#include "Memento.h"
#include "CodeManager.h"
#include "CodeVersion.h"

int main()
{
    printf("备忘录模式\n");
    printf("\n");

    CodeManager* manager = new CodeManager();

    CodeVersion* codeVersion = new CodeVersion(1001, "2021-3-27", "Initial version");

    // 提交初始版本
	printf("提交初始版本:\n");
	manager->commit(codeVersion->save());
 
	// 修改一个版本，增加了日志功能
	printf("\n提交一个版本，增加了日志功能:\n");
	codeVersion->setVersion(1002);
	codeVersion->setDate("2019-11-04");
	codeVersion->setLabel("Add log funciton");
	manager->commit(codeVersion->save());
 
	// 修改一个版本，增加了Qt图片浏览器
	printf("\n提交一个版本，增加了Qt图片浏览器:\n");
	codeVersion->setVersion(1003);
	codeVersion->setDate("2019-11-05");
	codeVersion->setLabel("Add Qt Image Browser");
	manager->commit(codeVersion->save());
 
	// 查看提交历史
	printf("\n查看提交历史\n");
	manager->codeLog();
 
	// 回退到上一个版本
	printf("\n回退到上一个版本\n");
	codeVersion->restore(manager->switchToPointedVersion(1));
 
	// 查看提交历史
	printf("\n查看提交历史\n");
	manager->codeLog();
 
	printf("\n\n");

    return 0;
}