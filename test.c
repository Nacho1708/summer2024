void test()
{
    TCanvas *c1 = new TCanvas();
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);
    hist->Fill(10);
    hist->Draw();
}

