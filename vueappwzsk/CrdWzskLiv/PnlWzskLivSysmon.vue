<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="12">
					<div>{{tag.Cpt}}</div>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<v-text-field
				class="my-2"
				readonly
				outlined
				v-model="continf.TxtCtp"
				:label="tag.CptCtp"
			/>

			<v-divider/>

			<div
				class="my-2"
				style="height:250px"
			>
				<!-- IP divPlt - INSERT -->
			</div>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLivSysmon',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLivSysmon.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLivSysmonDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLivSysmon"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLivSysmonData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLivSysmonData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWzskLivSysmon) this.continf = dpcheng.ContInfWzskLivSysmon;
				if (dpcheng.StatShrWzskLivSysmon) this.statshr = dpcheng.StatShrWzskLivSysmon;
				if (dpcheng.TagWzskLivSysmon) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLivSysmon);
					this.tag = dpcheng.TagWzskLivSysmon;
				}
				/*
<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLivSysmonData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngLive - BEGIN -->
				*/
				console.log("PnlWzskLivSysmon.handleDpchEngLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLivSysmonData") this.mergeDpchEngData(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLivSysmonLive") this.handleDpchEngLive(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
