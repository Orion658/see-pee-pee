package automation_testing;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;
import org.testng.Assert;
import org.testng.annotations.Test;

public class LoginTest {

	@Test
	public void practiceLoginTest() {
		WebDriver driver = new ChromeDriver();
		driver.get("https://practice.automationtesting.in/my-account/");

		// Enter first name, last name, and click on Login
		driver.findElement(By.id("username")).sendKeys("John");
		driver.findElement(By.id("password")).sendKeys("Doe");

		// Click on Login button
		driver.findElement(By.name("login")).click();

		// Verify the error message
		String errorMessage = driver.findElement(By.className("woocommerce-error")).getText();
		Assert.assertEquals(errorMessage,
				"Error: The password you entered for the username John is incorrect. Lost your password?");
		System.out.println("Error Message: " + errorMessage);

		driver.quit();
	}
}
