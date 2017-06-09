[1mdiff --git a/.project b/.project[m
[1mdeleted file mode 100644[m
[1mindex 0138f20..0000000[m
[1m--- a/.project[m
[1m+++ /dev/null[m
[36m@@ -1,11 +0,0 @@[m
[31m-<?xml version="1.0" encoding="UTF-8"?>[m
[31m-<projectDescription>[m
[31m-	<name>prog3</name>[m
[31m-	<comment></comment>[m
[31m-	<projects>[m
[31m-	</projects>[m
[31m-	<buildSpec>[m
[31m-	</buildSpec>[m
[31m-	<natures>[m
[31m-	</natures>[m
[31m-</projectDescription>[m
[1mdiff --git a/Napoleao/.cproject b/Napoleao/.cproject[m
[1mindex 9d57f29..cae075a 100644[m
[1m--- a/Napoleao/.cproject[m
[1m+++ b/Napoleao/.cproject[m
[36m@@ -22,15 +22,27 @@[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.c.compiler.514787895" name="Cross GCC Compiler" superClass="cdt.managedbuild.tool.gnu.cross.c.compiler">[m
 								<option defaultValue="gnu.c.optimization.level.none" id="gnu.c.compiler.option.optimization.level.1397488969" name="Optimization Level" superClass="gnu.c.compiler.option.optimization.level" useByScannerDiscovery="false" valueType="enumerated"/>[m
 								<option id="gnu.c.compiler.option.debugging.level.1544456098" name="Debug Level" superClass="gnu.c.compiler.option.debugging.level" useByScannerDiscovery="false" value="gnu.c.debugging.level.max" valueType="enumerated"/>[m
[32m+[m								[32m<option id="gnu.c.compiler.option.include.paths.231834165" name="Include paths (-I)" superClass="gnu.c.compiler.option.include.paths" useByScannerDiscovery="false" valueType="includePath">[m
[32m+[m									[32m<listOptionValue builtIn="false" value="&quot;${workspace_loc:/carteado}&quot;"/>[m
[32m+[m								[32m</option>[m
 								<inputType id="cdt.managedbuild.tool.gnu.c.compiler.input.1761157620" superClass="cdt.managedbuild.tool.gnu.c.compiler.input"/>[m
 							</tool>[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.cpp.compiler.1744961407" name="Cross G++ Compiler" superClass="cdt.managedbuild.tool.gnu.cross.cpp.compiler">[m
 								<option id="gnu.cpp.compiler.option.optimization.level.1332298437" name="Optimization Level" superClass="gnu.cpp.compiler.option.optimization.level" useByScannerDiscovery="false" value="gnu.cpp.compiler.optimization.level.none" valueType="enumerated"/>[m
 								<option id="gnu.cpp.compiler.option.debugging.level.931294310" name="Debug Level" superClass="gnu.cpp.compiler.option.debugging.level" useByScannerDiscovery="false" value="gnu.cpp.compiler.debugging.level.max" valueType="enumerated"/>[m
[32m+[m								[32m<option id="gnu.cpp.compiler.option.include.paths.427836472" name="Include paths (-I)" superClass="gnu.cpp.compiler.option.include.paths" useByScannerDiscovery="false" valueType="includePath">[m
[32m+[m									[32m<listOptionValue builtIn="false" value="&quot;${workspace_loc:/carteado}&quot;"/>[m
[32m+[m								[32m</option>[m
 								<inputType id="cdt.managedbuild.tool.gnu.cpp.compiler.input.1399532003" superClass="cdt.managedbuild.tool.gnu.cpp.compiler.input"/>[m
 							</tool>[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.c.linker.940078590" name="Cross GCC Linker" superClass="cdt.managedbuild.tool.gnu.cross.c.linker"/>[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.cpp.linker.1449047392" name="Cross G++ Linker" superClass="cdt.managedbuild.tool.gnu.cross.cpp.linker">[m
[32m+[m								[32m<option id="gnu.cpp.link.option.paths.576105873" name="Library search path (-L)" superClass="gnu.cpp.link.option.paths" useByScannerDiscovery="false" valueType="libPaths">[m
[32m+[m									[32m<listOptionValue builtIn="false" value="&quot;${workspace_loc:/carteado/Lib}&quot;"/>[m
[32m+[m								[32m</option>[m
[32m+[m								[32m<option id="gnu.cpp.link.option.libs.1008142835" name="Libraries (-l)" superClass="gnu.cpp.link.option.libs" useByScannerDiscovery="false" valueType="libs">[m
[32m+[m									[32m<listOptionValue builtIn="false" srcPrefixMapping="" srcRootPath="" value="carteado"/>[m
[32m+[m								[32m</option>[m
 								<inputType id="cdt.managedbuild.tool.gnu.cpp.linker.input.1949389546" superClass="cdt.managedbuild.tool.gnu.cpp.linker.input">[m
 									<additionalInput kind="additionalinputdependency" paths="$(USER_OBJS)"/>[m
 									<additionalInput kind="additionalinput" paths="$(LIBS)"/>[m
[36m@@ -38,16 +50,27 @@[m
 							</tool>[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.archiver.295535670" name="Cross GCC Archiver" superClass="cdt.managedbuild.tool.gnu.cross.archiver"/>[m
 							<tool id="cdt.managedbuild.tool.gnu.cross.assembler.857315787" name="Cross GCC Assembler" superClass="cdt.managedbuild.tool.gnu.cross.assembler">[m
[32m+[m								[32m<option id="gnu.both.asm.option.include.paths.258662154" name="Include paths (-I)" superClass="gnu.both.asm.option.include.paths" useByScannerDiscovery="false" valueType="includePath">[m
[32m+[m									[32m<listOptionValue builtIn="false" value="&quot;${workspace_loc:/carteado}&quot;"/>[m
[32m+[m								[32m</option>[m
 								<inputType id="cdt.managedbuild.tool.gnu.assembler.input.1933677650" superClass="cdt.managedbuild.tool.gnu.assembler.input"/>[m
 							</tool>[m
 						</toolChain>[m
 					</folderInfo>[m
 					<sourceEntries>[m
[31m-						<entry flags="VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="src"/>[m
[32m+[m						[32m<entry flags="VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name=""/>[m
 					</sourceEntries>[m
 				</configuration>[m
 			</storageModule>[m
[31m-			<storageModule moduleId="org.eclipse.cdt.core.externalSettings"/>[m
[32m+[m			[32m<storageModule moduleId="org.eclipse.cdt.core.externalSettings">[m
[32m+[m				[32m<externalSettings containerId="carteado;cdt.managedbuild.config.gnu.lib.debug.956521379" factoryId="org.eclipse.cdt.core.cfg.export.settings.sipplier">[m
[32m+[m					[32m<externalSetting>[m
[32m+[m						[32m<entry flags="VALUE_WORKSPACE_PATH" kind="includePath" name="/carteado"/>[m
[32m+[m						[32m<entry flags="VALUE_WORKSPACE_PATH" kind="libraryPath" name="/carteado/Lib"/>[m
[32m+[m						[32m<entry flags="RESOLVED" kind="libraryFile" name="carteado" srcPrefixMapping="" srcRootPath=""/>[m
[32m+[m					[32m</externalSetting>[m
[32m+[m				[32m</externalSettings>[m
[32m+[m			[32m</storageModule>[m
 		</cconfiguration>[m
 		<cconfiguration id="cdt.managedbuild.config.gnu.cross.exe.release.1175527295">[m
 			<storageModule buildSystemId="org.eclipse.cdt.managedbuilder.core.configurationDataProvider" id="cdt.managedbuild.config.gnu.cross.exe.release.1175527295" moduleId="org.eclipse.cdt.core.settings" name="Release">[m
[36m@@ -91,7 +114,7 @@[m
 						</toolChain>[m
 					</folderInfo>[m
 					<sourceEntries>[m
[31m-						<entry flags="VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name="src"/>[m
[32m+[m						[32m<entry flags="VALUE_WORKSPACE_PATH|RESOLVED" kind="sourcePath" name=""/>[m
 					</sourceEntries>[m
 				</configuration>[m
 			</storageModule>[m
[36m@@ -118,4 +141,12 @@[m
 	</storageModule>[m
 	<storageModule moduleId="org.eclipse.cdt.core.LanguageSettingsProviders"/>[m
 	<storageModule moduleId="org.eclipse.cdt.make.core.buildtargets"/>[m
[32m+[m	[32m<storageModule moduleId="refreshScope" versionNumber="2">[m
[32m+[m		[32m<configuration configurationName="Debug">[m
[32m+[m			[32m<resource resourceType="PROJECT" workspacePath="/Napoleao"/>[m
[32m+[m		[32m</configuration>[m
[32m+[m		[32m<configuration configurationName="Release">[m
[32m+[m			[32m<resource resourceType="PROJECT" workspacePath="/Napoleao"/>[m
[32m+[m		[32m</configuration>[m
[32m+[m	[32m</storageModule>[m
 </cproject>[m
[1mdiff --git a/Napoleao/.project b/Napoleao/.project[m
[1mindex 99e5ff6..c17edc4 100644[m
[1m--- a/Napoleao/.project[m
[1m+++ b/Napoleao/.project[m
[36m@@ -3,6 +3,7 @@[m
 	<name>Napoleao</name>[m
 	<comment></comment>[m
 	<projects>[m
[32m+[m		[32m<project>carteado</project>[m
 	</projects>[m
 	<buildSpec>[m
 		<buildCommand>[m
[1mdiff --git a/Napoleao/src/Napoleao.cpp b/Napoleao/src/Napoleao.cpp[m
[1mdeleted file mode 100644[m
[1mindex 6871708..0000000[m
[1m--- a/Napoleao/src/Napoleao.cpp[m
[1m+++ /dev/null[m
[36m@@ -1,19 +0,0 @@[m
[31m-//============================================================================[m
[31m-// Name        : Napoleao.cpp[m
[31m-// Author      : Vitor Russi[m
[31m-// Version     :[m
[31m-// Copyright   : Sem plagio pfv[m
[31m-// Description : Hello World in C++, Ansi-style[m
[31m-//============================================================================[m
[31m-[m
[31m-#include <iostream>[m
[31m-[m
[31m-int main() {[m
[31m-[m
[31m-[m
[31m-[m
[31m-[m
[31m-[m
[31m-[m
[31m-	return 0;[m
[31m-}[m
[1mdiff --git a/Paciencia/.settings/language.settings.xml b/Paciencia/.settings/language.settings.xml[m
[1mindex 9fb31f7..c1ecb79 100644[m
[1m--- a/Paciencia/.settings/language.settings.xml[m
[1m+++ b/Paciencia/.settings/language.settings.xml[m
[36m@@ -5,7 +5,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="68912254510028965" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[36m@@ -16,7 +16,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="68912254510028965" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[1mdiff --git a/Presidente/.settings/language.settings.xml b/Presidente/.settings/language.settings.xml[m
[1mindex c16f398..c967fb4 100644[m
[1m--- a/Presidente/.settings/language.settings.xml[m
[1m+++ b/Presidente/.settings/language.settings.xml[m
[36m@@ -5,7 +5,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-580989687574160606" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[36m@@ -16,7 +16,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-580989687574160606" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[1mdiff --git a/Truco/.settings/language.settings.xml b/Truco/.settings/language.settings.xml[m
[1mindex 1ece3f1..8994b9f 100644[m
[1m--- a/Truco/.settings/language.settings.xml[m
[1m+++ b/Truco/.settings/language.settings.xml[m
[36m@@ -5,7 +5,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="234159117178121975" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[36m@@ -16,7 +16,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="234159117178121975" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[1mdiff --git a/carteado/.settings/language.settings.xml b/carteado/.settings/language.settings.xml[m
[1mindex ced1829..629d331 100644[m
[1m--- a/carteado/.settings/language.settings.xml[m
[1m+++ b/carteado/.settings/language.settings.xml[m
[36m@@ -5,7 +5,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="68910520908585889" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569959709474821794" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[36m@@ -16,7 +16,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="68912254510028965" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
[36m@@ -27,7 +27,7 @@[m
 			<provider copy-of="extension" id="org.eclipse.cdt.ui.UserLanguageSettingsProvider"/>[m
 			<provider-reference id="org.eclipse.cdt.core.ReferencedProjectsLanguageSettingsProvider" ref="shared-provider"/>[m
 			<provider-reference id="org.eclipse.cdt.managedbuilder.core.MBSLanguageSettingsProvider" ref="shared-provider"/>[m
[31m-			<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="68912254510028965" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
[32m+[m			[32m<provider class="org.eclipse.cdt.managedbuilder.language.settings.providers.GCCBuiltinSpecsDetector" console="false" env-hash="-569962321766076710" id="org.eclipse.cdt.managedbuilder.core.GCCBuiltinSpecsDetector" keep-relative-paths="false" name="CDT GCC Built-in Compiler Settings" parameter="${COMMAND} ${FLAGS} -E -P -v -dD &quot;${INPUTS}&quot;" prefer-non-shared="true">[m
 				<language-scope id="org.eclipse.cdt.core.gcc"/>[m
 				<language-scope id="org.eclipse.cdt.core.g++"/>[m
 			</provider>[m
