package rediff_mail;

import org.junit.Assert;
import org.junit.Test;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

public class LoginTest {

	@Test
	public void practiceLoginTest() {
		WebDriver driver = new ChromeDriver();
		driver.get("https://mail.rediff.com/cgi-bin/login.cgi");

		// Enter Username and Password
		driver.findElement(By.id("login1")).sendKeys("test_username");
		driver.findElement(By.id("password")).sendKeys("abcd");

		// Click on Login
		driver.findElement(By.name("proceed")).click();

		// human verification
		driver.findElement(By.id("imagetext")).sendKeys("AB77");
		driver.findElement(By.cssSelector("input[type='submit'][value='Submit']")).click();

		WebElement errorMessageElement = driver.findElement(By.id("errBox"));
		String actualErrorMessage = errorMessageElement.findElement(By.className("errmsg")).getText();

		// Assert the text using TestNG's assertEquals
		String expectedErrorMessage = "Invalid code";
		Assert.assertEquals(actualErrorMessage, expectedErrorMessage, "Human verification paseed");

		// Verify the error message
//		String actualErrorMessage = driver.findElement(By.id("div_alert")).getText();
//		String expectedErrorMessage = "Your username or password is incorrect.";
//
//		// Assert equals to verify the error message
//		Assert.assertEquals(actualErrorMessage, expectedErrorMessage, "Error message does not match.");

		driver.close();
	}

}
