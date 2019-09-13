import org.jetbrains.kotlin.gradle.plugin.KotlinSourceSet
import org.jetbrains.kotlin.gradle.tasks.KotlinCompile

val pid : String by project

plugins {
	kotlin("jvm") version "1.3.41"
	application
}

application {
	mainClassName = pid
}

sourceSets {
    getByName("main") {
        withConvention(KotlinSourceSet::class) {
			listOf(java, kotlin).forEach {
				it.srcDirs("src")
			}
        }
    }
}

repositories {
	maven("https://maven.aliyun.com/repository/public")
    jcenter()
}

dependencies {
    compile(kotlin("stdlib"))
}

tasks.withType<KotlinCompile> {
    kotlinOptions.jvmTarget = "1.8"
}